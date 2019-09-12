/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 16:33:43 by efischer          #+#    #+#             */
/*   Updated: 2019/09/12 18:03:56 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	canonic_mode_on(struct termios *old_tty)
{
	struct termios	tty;

	tcgetattr(0, &tty);
	*old_tty = tty;
	tty.c_lflag &= ~(ECHO | ICANON);
	tty.c_cc[VMIN] = 1;
	tty.c_cc[VTIME] = 1;
	tcsetattr(0, TCSAFLUSH, &tty);
}

static void	canonic_mode_off(struct termios old_tty)
{
	tcsetattr(0, TCSAFLUSH, &old_tty);
}

static void	ft_select(t_list *lst)
{
	char	buf[READ_SIZE];
	ssize_t	ret;

	cl_screen();
	ft_lstprint(lst, print_list);
	while ((ret = read(0, buf, READ_SIZE)) >= 0)
	{
		buf[ret] = '\0';
		cl_screen();
		ft_lstprint(lst, print_list);
	}
}

int		main(int ac, char **av)
{
	struct termios	old_tty;
	t_list			*lst;
	int				ret;

	lst = NULL;
	if (ac < 2)
	{
		ft_putendl_fd("Usage: ft_select ...", 2);
		return (EXIT_SUCCESS);
	}
	get_list(&lst, av + 1);
	canonic_mode_on(&old_tty);
	if ((ret = init_entry()) == TRUE)
		ft_select(lst);
	canonic_mode_off(old_tty);
	return (ret);
}
