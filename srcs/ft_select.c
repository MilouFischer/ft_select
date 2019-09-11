/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 11:34:24 by efischer          #+#    #+#             */
/*   Updated: 2019/09/11 17:22:56 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int	put_termcap(int	termcap)
{
	int		ret;

	ret = ft_putchar((char)termcap);
	return (ret);
}

static void	cl_screen(void)
{
	char	*cl_cap;

	if (tgetflag("cl") == SUCCESS)
	{
		cl_cap = tgetstr("cl", NULL);
		tputs(cl_cap, 1, put_termcap);
	}
}

static void	raw_mode_on(struct termios *old_tty)
{
	struct termios	tty;

	tcgetattr(0, old_tty);
	tty = *old_tty;
	tty.c_lflag &= ~(ECHO | ICANON);
	tty.c_cc[VMIN] = 1;
	tty.c_cc[VTIME] = 1;
	tcsetattr(0, TCSAFLUSH, &tty);
}

static void	raw_mode_off(struct termios old_tty)
{
	tcsetattr(0, TCSAFLUSH, &old_tty);
}

static int	ft_select(char **av, t_cap cap)
{
	struct termios	old_tty;
	char			buf[BUF_SIZE];
	int				ret;

	raw_mode_on(&old_tty);
	cl_screen();
	ft_print_tab(av);
	while ((ret = read(0, &buf, BUF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		manage_key(buf, cap);
		cl_screen();
		ft_print_tab(av);
	}
	raw_mode_off(old_tty);
	return (ret);
}

int			main(int ac, char **av)
{
	t_cap	cap;
	int		ret;

	if (ac < 2)
	{
		ft_putendl_fd("usage: ft_select ...", 2);
		exit(EXIT_FAILURE);
	}
	ret = init_entry();
	init_cap(&cap);
	if (ret == TRUE)
		ft_select(av + 1, cap);
	return (ret);
}
