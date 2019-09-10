/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 11:45:33 by efischer          #+#    #+#             */
/*   Updated: 2019/09/10 14:59:35 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libft.h"
# include <curses.h>
# include <term.h>

# define SPACE	0x31
# define ESC	0x35
# define LEFT	0x7B
# define RIGHT	0x7C
# define DOWN	0x7D
# define UP		0x7E

int		init_entry(void);

#endif
