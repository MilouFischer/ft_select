/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:14:50 by efischer          #+#    #+#             */
/*   Updated: 2019/09/18 17:35:09 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	st_end(t_list *lst, t_machine *machine)
{
	(void)lst;
	(void)machine;
	cl_screen();
	exit(EXIT_SUCCESS);
}
