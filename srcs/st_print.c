/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:43:44 by efischer          #+#    #+#             */
/*   Updated: 2019/09/19 14:26:41 by efischer         ###   ########.fr       */
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

void	column_display(t_list *lst)
{
	t_select	**elem;
	char		*str;
	char		*out;	
	size_t		nb_arg;
	size_t		i;
	size_t		len;
	int			y;

	y = 0;
	str = NULL;
	out = NULL;
	elem = get_arg_tab(lst, &nb_arg);
	while (y < ((t_select*)(lst->content))->y_max)
	{
		i = y;
		while (i < nb_arg)
		{
			len = ((t_select*)(lst->content))->pad - ft_strlen(elem[i]->arg);
			str = apply_flag(elem[i]);	
			out = ft_join_free(out, str, 3);
			if (elem[i]->x != elem[i]->x_max)
				out = ft_join_free(out, ft_asprintf("%-*s", len + 1, " "), 3);
			i += ((t_select*)(lst->content))->y_max;
		}
		cl_screen();
		out = ft_join_free(out, "\n", 1);
		y++;
	}
	ft_putstr(out);
	ft_strdel(&out);
	free(elem);
}

void	st_print(t_list *lst, t_machine *machine)
{
	column_display(lst);
	machine->state = ST_INPUT;
	ft_select(lst, machine);
}
