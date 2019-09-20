/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:14:50 by efischer          #+#    #+#             */
/*   Updated: 2019/09/20 11:34:00 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	st_end(t_list *lst, t_machine *machine)
{
	(void)machine;
	ft_lstdel(&lst, del_list);
	cl_screen();
	ft_putstr_fd(glob.out, glob.tty_fd);
	exit(EXIT_SUCCESS);
}
