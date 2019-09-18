/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 13:23:49 by efischer          #+#    #+#             */
/*   Updated: 2019/09/18 14:33:29 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	curs_up(t_list *lst, t_list *curs, t_machine *machine)
{
	(void)lst;
	(void)curs;
	(void)machine;
	ft_putendl("Move cursor up");
}

void	curs_down(t_list *lst, t_list *curs, t_machine *machine)
{
	(void)lst;
	(void)curs;
	(void)machine;
	ft_putendl("Move cursor down");
}

void	curs_right(t_list *lst, t_list *curs, t_machine *machine)
{
	(void)lst;
	(void)curs;
	(void)machine;
	ft_putendl("Move cursor right");
}

void	curs_left(t_list *lst, t_list *curs, t_machine *machine)
{
	(void)lst;
	(void)curs;
	(void)machine;
	ft_putendl("Move cursor left");
}
