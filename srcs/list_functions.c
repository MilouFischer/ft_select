/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 16:48:32 by efischer          #+#    #+#             */
/*   Updated: 2019/09/12 17:12:47 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	get_list(t_list **lst, char **av)
{
	t_select	select;
	size_t		i;

	i = 0;
	while (av[i] != NULL)
	{
		ft_bzero(&select, sizeof(select));
		select.arg = av[i];
		ft_lstaddend(lst, ft_lstnew(&select, sizeof(select)));
		i++;
	}
}

void	print_list(t_list *lst, t_list **elem)
{
	char	*new;

	new = ((t_select*)(lst->content))->arg;
	new = ft_strjoin(new, "\n");
	*elem = ft_lstnew(new, ft_strlen(new));
}
