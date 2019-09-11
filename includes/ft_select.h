/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 11:45:33 by efischer          #+#    #+#             */
/*   Updated: 2019/09/11 17:28:38 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libft.h"
# include <curses.h>
# include <term.h>

typedef struct	s_cap
{
		char	*cl;
		char	*ku;
		char	*kd;
		char	*kl;
		char	*kr;
}				t_cap;

int				init_entry(void);
void			manage_key(char *buf, t_cap cap);
void			init_cap(t_cap *cap);

#endif
