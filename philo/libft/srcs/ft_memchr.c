/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:24:25 by mliboz            #+#    #+#             */
/*   Updated: 2021/11/03 07:50:30 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	int		i;
	char	*cs;

	cs = (char *)s;
	i = 0;
	while (n > 0)
	{
		if (cs[i] == c)
			return ((char *)s + i);
		i++;
		n--;
	}
	return (0);
}
