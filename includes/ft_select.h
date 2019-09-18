/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 11:45:33 by efischer          #+#    #+#             */
/*   Updated: 2019/09/18 16:58:36 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libft.h"
# include <curses.h>
# include <term.h>

# define READ_SIZE	8
# define NB_FCT		3
# define NB_KEY		6
# define K_UP		"\E[A"
# define K_DOWN		"\E[B"
# define K_RIGHT	"\E[C"
# define K_LEFT		"\E[D"
# define K_ESC		"\E"
# define K_SPACE	" "
# define T_AB	"AB"
# define T_AF	"AF"
# define T_US	"us"
# define T_ME	"me"
# define T_CO   "co"
# define T_LI	"li"
# define T_CL	"cl"
# define F_AB	0x00000001
# define F_US	0x00000002
# define F_ME	0x00000004

enum
{
					ST_INPUT,
					ST_PRINT,
					ST_END
};

typedef struct		s_machine
{
		int			state;
}					t_machine;

typedef struct		s_select
{
		char		*arg;
		uint64_t	flag;
}					t_select;

typedef struct		s_termcap
{
		char		*ab;
		char		*af;
		char		*us;
		char		*me;
}					t_termcap;

typedef void	(t_state_fct)(t_list*, t_machine*);
typedef void	(t_key_fct)(t_list*, t_list*, t_machine*);

int					init_entry(void);
void				get_list(t_list **lst, char **av);
void				get_termcap(t_termcap *termcap);
void				ft_select(t_list *lst, t_machine *machine);
void				st_input(t_list *lst, t_machine *machine);
void				st_end(t_list *lst, t_machine *machine);
void				curs_up(t_list *lst, t_list *curs, t_machine *machine);
void				curs_down(t_list *lst, t_list *curs, t_machine *machine);
void				curs_right(t_list *lst, t_list *curs, t_machine *machine);
void				curs_left(t_list *lst, t_list *curs, t_machine *machine);
void				quit(t_list *lst, t_list *curs, t_machine *machine);
void				select_elem(t_list *lst, t_list *curs, t_machine *machine);
void				st_print(t_list *lst, t_machine *machine);
void				print_list(t_list *lst, t_list **elem);
void				del_list(void *content, size_t content_size);
void				cl_screen(void);

#endif
