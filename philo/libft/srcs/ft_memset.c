/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:31:04 by mliboz            #+#    #+#             */
/*   Updated: 2021/11/03 15:21:07 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	int		i;
	char	*cb;

	i = 0;
	cb = (char *)b;
	while (len--)
	{
		cb[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
