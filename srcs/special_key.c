/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 13:37:23 by efischer          #+#    #+#             */
/*   Updated: 2019/09/19 17:49:44 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	quit(t_list *lst, t_list **curs, t_machine *machine)
{
	(void)lst;
	(void)curs;
	ft_lstdel(&lst, del_list);
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
