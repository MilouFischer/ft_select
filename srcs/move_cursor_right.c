/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor_right.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:46:17 by efischer          #+#    #+#             */
/*   Updated: 2019/09/19 17:31:45 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	check_x_y_max(int *x, int *y, t_list *lst)
{
	if (*x >= ((t_select*)(lst->content))->x_max
		|| *x * ((t_select*)(lst->content))->y_max + *y + 1
		> (int)ft_lstlen(lst))
	{
		*x = 0;
		*y += 1;
		if (*y >= ((t_select*)(lst->content))->y_max)
			*y = 0;
	}
}

void	curs_right(t_list *lst, t_list **curs, t_machine *machine)
{
	int		x;
	int		y;

	(void)machine;
	((t_select*)((*curs)->content))->flag &= ~(F_US);
	x = ((t_select*)((*curs)->content))->x + 1;
	y = ((t_select*)((*curs)->content))->y;
	check_x_y_max(&x, &y, lst);
	ft_printf("x: %d, y: %d\n", x, y);
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
	((t_select*)((*curs)->content))->flag |= F_US;
}
