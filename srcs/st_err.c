/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_err.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 11:59:16 by efischer          #+#    #+#             */
/*   Updated: 2019/09/20 12:07:12 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	st_err(t_list *lst, t_machine *machine)
{
	(void)machine;
	ft_putendl_fd("ERROR", 2);
	ft_lstdel(&lst, del_list);
	exit(EXIT_FAILURE);
}
