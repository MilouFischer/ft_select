/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_y_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 13:14:28 by efischer          #+#    #+#             */
/*   Updated: 2019/09/19 13:39:52 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		elem_to_list(t_list *lst, t_select **elem)
{
	size_t	i;

	i = 0;
	while (lst != NULL)
	{
		lst->content = elem[i];
		lst = lst->next;
		i++;
	}
}

t_select		**get_arg_tab(t_list *lst, size_t *nb_arg)
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

static void		get_x_y_for_each(t_select **elem, size_t nb_arg)
{
	size_t	total_line;
	size_t	nb_line;
	size_t	i;

	total_line = get_total_line(elem, nb_arg);
	nb_line = 0;
	while (nb_line < total_line)
	{
		i = nb_line;
		while (i < nb_arg)
		{
			elem[i]->x = (i - nb_line) / total_line;
			elem[i]->y = nb_line;
			elem[i]->x_max = nb_arg / total_line;
			elem[i]->y_max = total_line;
			i += total_line;
		}
		nb_line++;
	}
}

void			x_y_elem(t_list *lst)
{
	t_select		**elem;
	size_t			nb_arg;

	elem = get_arg_tab(lst, &nb_arg);
	if (elem == NULL || (*elem)->pad - 1 <= 0)
		return ;
	get_x_y_for_each(elem, nb_arg);
	elem_to_list(lst, elem);
	free(elem);
}
