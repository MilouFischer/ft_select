/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:43:44 by efischer          #+#    #+#             */
/*   Updated: 2019/09/18 17:35:55 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

char	*apply_flag(t_list *lst)
{
	static t_termcap	termcap;
	char				*str;
	char				*tmp;

	get_termcap(&termcap);
	str = ft_strdup(((t_select*)(lst->content))->arg);
	if ((((t_select*)(lst->content))->flag & F_SO) == F_SO)
	{
		tmp = str;
		str = ft_asprintf("%s%s%s", termcap.so, tmp, termcap.me);
		ft_strdel(&tmp);
	}
	if ((((t_select*)(lst->content))->flag & F_US) == F_US)
	{
		tmp = str;
		str = ft_asprintf("%s%s%s", termcap.us, tmp, termcap.me);
		ft_strdel(&tmp);
	}
	return (str);
}

void	st_print(t_list *lst, t_machine *machine)
{
	t_list	*head;
	char	*str;
	char	*out;

	str = NULL;
	out = NULL;
	head = lst;
	while (lst != NULL)
	{
		str = apply_flag(lst);
		out = ft_join_free(out, str, 3);
		out = ft_join_free(out, "\n", 1);
		lst = lst->next;
	}
	//cl_screen();
	ft_putstr(out);
	machine->state = ST_INPUT;
	ft_select(head, machine);
}
