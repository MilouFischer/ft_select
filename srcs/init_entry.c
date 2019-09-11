/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_entry.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 15:28:29 by efischer          #+#    #+#             */
/*   Updated: 2019/09/11 17:28:35 by efischer         ###   ########.fr       */
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

void	init_cap(t_cap *cap)
{
	ft_bzero(cap, sizeof(cap));
	if (tgetflag("cl") == SUCCESS)
		cap->cl = tgetstr("cl", NULL);
	if (tgetflag("ku") == SUCCESS)
		cap->ku = tgetstr("ku", NULL);
	if (tgetflag("kd") == SUCCESS)
		cap->kd = tgetstr("kd", NULL);
	if (tgetflag("kl") == SUCCESS)
		cap->kl = tgetstr("kl", NULL);
	if (tgetflag("kr") == SUCCESS)
		cap->kr = tgetstr("kr", NULL);
}
