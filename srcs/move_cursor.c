/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 13:23:49 by efischer          #+#    #+#             */
/*   Updated: 2019/09/19 14:36:48 by efischer         ###   ########.fr       */
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
	t_list	*head;
	int		x;
	int		y;

	(void)machine;
	head = lst;
	((t_select*)((*curs)->content))->flag &= ~(F_US);
	x = ((t_select*)((*curs)->content))->x;
	y = ((t_select*)((*curs)->content))->y + 1;
	if (y >= ((t_select*)((*curs)->content))->y_max)
	{
		x += (y / ((t_select*)((*curs)->content))->y_max);
		x %= ((t_select*)((*curs)->content))->x_max;
		ft_printf("x: %d\n", x);
		y %= ((t_select*)((*curs)->content))->y_max;
	}
	ft_printf("x: %d, y: %d\n", x, y);
	while (lst != NULL)
	{
		if (((t_select*)(lst->content))->x == x && ((t_select*)(lst->content))->y == y)
		{
			*curs = lst;
			break ;
		}
		lst = lst->next;
	}
	if (lst == NULL)
		*curs = head;
	((t_select*)((*curs)->content))->flag |= F_US;
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
