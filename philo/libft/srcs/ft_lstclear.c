/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:38:32 by mliboz            #+#    #+#             */
/*   Updated: 2021/12/13 11:10:52 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*save;

	if (!*lst)
		return (0);
	while (*lst)
	{
		save = (*lst)->next;
		if ((*lst)->content)
			del((*lst)->content);
		free(*lst);
		*lst = save;
	}
	*lst = 0;
	return (0);
}
