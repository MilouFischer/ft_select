/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 13:23:49 by efischer          #+#    #+#             */
/*   Updated: 2019/09/19 14:13:28 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	curs_up(t_list *lst, t_list **curs, t_machine *machine)
{
	(void)lst;
	(void)curs;
	(void)machine;
	ft_putendl("Move cursor up");
}

void	curs_down(t_list *lst, t_list **curs, t_machine *machine)
{
	int		x;
	int		y;

	(void)machine;
	((t_select*)((*curs)->content))->flag &= ~(F_US);
	x = ((t_select*)((*curs)->content))->x;
	y = ((t_select*)((*curs)->content))->y + 1;
	if (y >= ((t_select*)((*curs)->content))->y_max)
	{
		x += (y / ((t_select*)((*curs)->content))->y_max) % ((t_select*)((*curs)->content))->x_max;
		y %= ((t_select*)((*curs)->content))->y_max;
	}
	while (lst != NULL)
	{
		if (((t_select*)(lst->content))->x == x && ((t_select*)(lst->content))->y == y)
		{
			((t_select*)(lst->content))->flag |= F_US;
			*curs = lst;
			break ;
		}
		lst = lst->next;
	}
}

void	curs_right(t_list *lst, t_list **curs, t_machine *machine)
{
	(void)lst;
	(void)curs;
	(void)machine;
	ft_putendl("Move cursor right");
}

void	curs_left(t_list *lst, t_list **curs, t_machine *machine)
{
	(void)lst;
	(void)curs;
	(void)machine;
	ft_putendl("Move cursor left");
}
