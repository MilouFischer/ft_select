/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 13:23:49 by efischer          #+#    #+#             */
/*   Updated: 2019/09/19 15:11:37 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	check_x_y_max_up(int *x, int *y, t_list *lst)
{
	if (*y < 0)
	{
		*x -= (*y / ((t_select*)(lst->content))->y_max) + 1;
		*y = ft_abs(*y) % ((t_select*)(lst->content))->y_max;
	}
	if (*x < 0)
		*x = ((t_select*)(lst->content))->x_max;
}

static void	check_x_y_max_down(int *x, int *y, t_list *lst)
{
	if (*y >= ((t_select*)(lst->content))->y_max
		|| *x >= ((t_select*)(lst->content))->x_max)
	{
		*x += (*y / ((t_select*)(lst->content))->y_max);
		*x %= ((t_select*)(lst->content))->x_max;
		*y %= ((t_select*)(lst->content))->y_max;
	}
}

void	curs_up(t_list *lst, t_list **curs, t_machine *machine)
{
	t_list	*head;
	int		x;
	int		y;

	(void)machine;
	((t_select*)((*curs)->content))->flag &= ~(F_US);
	x = ((t_select*)((*curs)->content))->x;
	y = ((t_select*)((*curs)->content))->y - 1;
	check_x_y_max_up(&x, &y, *curs);
	ft_printf("x: %d, y: %d\n", x, y);
	while (lst != NULL)
	{
		if (((t_select*)(lst->content))->x == x
			&& ((t_select*)(lst->content))->y == y)
		{
			*curs = lst;
			break ;
		}
		if (lst->next == NULL)
			head = lst;
		lst = lst->next;
	}
	if (lst == NULL)
		*curs = head;
	((t_select*)((*curs)->content))->flag |= F_US;
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
	check_x_y_max_down(&x, &y, *curs);
	while (lst != NULL)
	{
		if (((t_select*)(lst->content))->x == x
			&& ((t_select*)(lst->content))->y == y)
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
