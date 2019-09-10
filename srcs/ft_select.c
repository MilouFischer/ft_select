/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 11:34:24 by efischer          #+#    #+#             */
/*   Updated: 2019/09/10 18:40:24 by efischer         ###   ########.fr       */
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

static void	raw_mode(void)
{
	struct termios	raw;

	tcgetattr(0, &raw);
	raw.c_lflag &= ~(ECHO | ICANON);
	tcsetattr(0, TCSAFLUSH, &raw);
}

static void	ft_select(char **av)
{
	char	buf;

	raw_mode();
	cl_screen();
	ft_print_tab(av);
	while (read(0, &buf, 1) > 0 && buf != 'q')
	{
		cl_screen();
		ft_print_tab(av);
	}
}

int			main(int ac, char **av)
{
	int		ret;

	if (ac < 2)
	{
		ft_putendl_fd("usage: ft_select ...", 2);
		exit(EXIT_FAILURE);
	}
	ret = init_entry();
	if (ret == TRUE)
		ft_select(av + 1);
	return (ret);
}
