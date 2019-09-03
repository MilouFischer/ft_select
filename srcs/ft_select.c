/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 11:34:24 by efischer          #+#    #+#             */
/*   Updated: 2019/09/03 15:24:54 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		main(int ac, char **av)
{
	int		ret;

	if (ac < 2)
	{
		ft_putendl_fd("usage: ft_select ...", 2);
		exit(EXIT_FAILURE);
	}
	if ((ret = init_entry()) != TRUE)
		return (ret);
	while (1)
		ft_print_tab(av + 1);
	return (EXIT_SUCCESS);
}
