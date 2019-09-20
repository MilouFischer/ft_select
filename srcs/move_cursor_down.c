/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor_down.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:46:06 by efischer          #+#    #+#             */
/*   Updated: 2019/09/20 11:27:56 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_select.h"

static void	check_x_y_max(int *x, int *y, t_list *lst)
{
	if (*y >= glob.y_max || *x * glob.y_max + *y + 1 > (int)ft_lstlen(lst))
	{
		*y = 0;
		*x += 1;
		if (*x >= glob.x_max)
			*x = 0;
	}
}

void	curs_down(t_list *lst, t_list **curs, t_machine *machine)
{
	int		x;
	int		y;

	(void)machine;
	((t_select*)((*curs)->content))->flag &= ~(F_US);
	x = ((t_select*)((*curs)->content))->x;
	y = ((t_select*)((*curs)->content))->y + 1;
	check_x_y_max(&x, &y, lst);
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
