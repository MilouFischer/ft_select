/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 15:05:53 by efischer          #+#    #+#             */
/*   Updated: 2019/09/03 15:20:06 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		init_entry(void)
{
	char	*term;
	int		ret;

	term = getenv("TERM");
	ret = tgetent(NULL, term);
	if (term == NULL)
		ft_putendl_fd("TERM not set", 2);
	else if (ret == -1)
		ft_putendl_fd("Could not access termcap database", 2);
	else if (ret == 0)
		ft_dprintf(2, "%s not defined in termcap database", term);
	return (ret);
}
