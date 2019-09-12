/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 11:45:33 by efischer          #+#    #+#             */
/*   Updated: 2019/09/12 18:03:53 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libft.h"
# include <curses.h>
# include <term.h>

# define READ_SIZE	8
# define K_UP		"\E[A"
# define K_DOWN		"\E[B"
# define K_RIGHT	"\E[C"
# define K_LEFT		"\E[D"
# define K_ESC		"\E"
# define K_SPACE

typedef struct		s_select
{
		char		*arg;
		uint64_t	flag;
}					t_select;

int					init_entry(void);
void				get_list(t_list **lst, char **av);
void				print_list(t_list *lst, t_list **elem);
void				cl_screen(void);

#endif
