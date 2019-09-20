/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 13:37:23 by efischer          #+#    #+#             */
/*   Updated: 2019/09/20 11:33:01 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	quit(t_list *lst, t_list **curs, t_machine *machine)
{
	(void)lst;
	(void)curs;
	machine->state = ST_END;
}

void	select_elem(t_list *lst, t_list **curs, t_machine *machine)
{
	(void)lst;
	(void)machine;
	if ((((t_select*)((*curs)->content))->flag & F_SO) == F_SO)
		((t_select*)((*curs)->content))->flag &= ~(F_SO);
	else
		((t_select*)((*curs)->content))->flag |= F_SO;
	curs_down(lst, curs, machine);
}

void	return_elem(t_list *lst, t_list **curs, t_machine *machine)
{
	char	*str;
	char	*tmp;

	(void)curs;
	str = NULL;
	while (lst != NULL)
	{
		if ((((t_select*)(lst->content))->flag & F_SO) == F_SO)
		{
			if (str == NULL)
				str = ft_strdup(((t_select*)(lst->content))->arg);
			else
			{
				tmp = str;
				str = ft_asprintf("%s %s", tmp, ((t_select*)(lst->content))->arg);
				ft_strdel(&tmp);
			}
		}
		lst = lst->next;
	}
	glob.out = str;
	machine->state = ST_END;
}
