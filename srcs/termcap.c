/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:35:18 by efischer          #+#    #+#             */
/*   Updated: 2019/09/18 17:34:15 by efischer         ###   ########.fr       */
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

	if (tgetflag(T_CL) == 0)
	{
		cl_cap = tgetstr(T_CL, NULL);
		tputs(cl_cap, 1, print_cap);
	}
}

void		get_termcap(t_termcap *termcap)
{
		termcap->so = tgetstr(T_SO, NULL);
		termcap->us = tgetstr(T_US, NULL);
		termcap->me = tgetstr(T_ME, NULL);
}

int			init_entry(void)
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
