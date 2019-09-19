/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:43:44 by efischer          #+#    #+#             */
/*   Updated: 2019/09/19 11:28:35 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	st_print(t_list *lst, t_machine *machine)
{
	column_display();
	machine->state = ST_INPUT;
	ft_select(lst, machine);
}
