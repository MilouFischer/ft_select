/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 16:48:32 by efischer          #+#    #+#             */
/*   Updated: 2019/09/19 12:24:53 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	get_pad(char **av, size_t *pad)
{
	size_t	len;
	size_t	i;

	i = 0;
	while (av[i] != NULL)
	{
		if ((len = ft_strlen(av[i])) > *pad)
			*pad = len;
		i++;
	}
	if (*pad != 0)
		pad++;
}

void		get_list(t_list **lst, char **av)
{
	t_select	select;
	size_t		pad;
	size_t		i;

	i = 0;
	pad = 0;
	get_pad(av, &pad);
	while (av[i] != NULL)
	{
		ft_bzero(&select, sizeof(select));
		select.arg = av[i];
		select.pad = pad;
		ft_lstaddend(lst, ft_lstnew(&select, sizeof(select)));
		i++;
	}
}

void		print_list(t_list *lst, t_list **elem)
{
	char	*new;

	new = ((t_select*)(lst->content))->arg;
	new = ft_strjoin(new, "\n");
	*elem = ft_lstnew(new, ft_strlen(new));
}

void		del_list(void *content, size_t content_size)
{
	(void)content_size;
	ft_memdel(&content);
}
