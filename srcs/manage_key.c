/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 12:00:25 by efischer          #+#    #+#             */
/*   Updated: 2019/09/11 17:28:29 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	manage_key(char	*buf, t_cap cap)
{
	if (ft_strequ(buf, cap.ku) == TRUE)
		ft_putendl("Up");
	else if (ft_strequ(buf, cap.kd) == TRUE)
		ft_putendl("Down");
	else if (ft_strequ(buf, cap.kr) == TRUE)
		ft_putendl("Right");
	else if (ft_strequ(buf, cap.kl) == TRUE)
		ft_putendl("Left");
	else
		ft_printf("cap.ku: %s, cap.kd: %s, cap.kr: %s, cap.kl: %s\n",
				cap.ku, cap.kd, cap.kr, cap.kl);
}
