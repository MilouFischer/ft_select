/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   column_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 09:53:50 by efischer          #+#    #+#             */
/*   Updated: 2019/09/19 12:05:20 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

char	*apply_flag(t_select *elem)
{
	static t_termcap	termcap;
	char				*str;
	char				*tmp;

	get_termcap(&termcap);
	str = ft_strdup(elem->arg);
	if ((elem->flag & F_SO) == F_SO)
	{
		tmp = str;
		str = ft_asprintf("%s%s%s", termcap.so, tmp, termcap.me);
		ft_strdel(&tmp);
	}
	if ((elem->flag & F_US) == F_US)
	{
		tmp = str;
		str = ft_asprintf("%s%s%s", termcap.us, tmp, termcap.me);
		ft_strdel(&tmp);
	}
	return (str);
}

static t_select	**get_arg_tab(t_list *lst, size_t *nb_arg)
{
	t_select	**elem;
	size_t		i;

	i = 0;
	*nb_arg = ft_lstlen(lst);
	elem = (t_select**)malloc(sizeof(t_select*) * (*nb_arg + 1));
	if (elem == NULL)
		return (NULL);
	while (i < *nb_arg && lst != NULL)
	{
		elem[i++] = (t_select*)(lst->content);
		lst = lst->next;
	}
	elem[i] = NULL;
	return (elem);
}

static size_t	get_total_line(t_select **elem, size_t nb_arg)
{
	size_t			nb_max_arg_by_line;
	size_t			total_line;
	struct winsize	ws;

	total_line = 1;
	ioctl(0, TIOCGWINSZ, &ws);
	nb_max_arg_by_line = ws.ws_col / (*elem)->pad;
	if (nb_max_arg_by_line != 0)
		total_line = nb_arg / nb_max_arg_by_line + 1;
	return (total_line);
}

static void		fill_line(char **buf, t_select *elem)
{
	char	*str;
	size_t	len;

	len = elem->pad - ft_strlen(elem->arg);
	str = apply_flag(elem);
	*buf = ft_join_free(*buf, str, 3);
	*buf = ft_join_free(*buf, ft_asprintf("%-*s", len + 1, " "), 3);
}

static void		print_column(t_select **elem, size_t nb_arg)
{
	size_t	total_line;
	size_t	nb_line;
	size_t	i;
	char	*buf;

	buf = NULL;
	total_line = get_total_line(elem, nb_arg);
	nb_line = 0;
	while (nb_line < total_line)
	{
		i = nb_line;
		while (i < nb_arg)
		{
			fill_line(&buf, elem[i]);
			i += total_line;
		}
		buf = ft_join_free(buf, "\n", 1);
		nb_line++;
	}
	cl_screen();
	ft_putstr(buf);
	ft_strdel(&buf);
}

void			column_display(t_list *lst)
{
	t_select		**elem;
	size_t			nb_arg;

	elem = get_arg_tab(lst, &nb_arg);
	if (elem == NULL || (*elem)->pad - 1 <= 0)
		return ;
	print_column(elem, nb_arg);
	free(elem);
}
