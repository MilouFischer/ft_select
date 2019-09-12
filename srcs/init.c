/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 16:40:56 by efischer          #+#    #+#             */
/*   Updated: 2019/09/12 17:13:26 by efischer         ###   ########.fr       */
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
		ft_putendl_fd("Termcap database not found", 2);
	else if (ret == 0)
		ft_putendl_fd("Terminal type undefined in termcap database", 2);
	return (ret);
}
