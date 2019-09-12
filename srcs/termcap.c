/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:35:18 by efischer          #+#    #+#             */
/*   Updated: 2019/09/12 18:03:55 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int	print_cap(int cap)
{
	return (ft_putchar(cap));
}

void		cl_screen(void)
{
	char	*cl_cap;

	if (tgetflag("cl") == 0)
	{
		cl_cap = tgetstr("cl", NULL);
		tputs(cl_cap, 1, print_cap);
	}
}
