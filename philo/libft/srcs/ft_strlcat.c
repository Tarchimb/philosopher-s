/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:02:06 by mliboz            #+#    #+#             */
/*   Updated: 2021/11/29 09:28:30 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

unsigned int	ft_strlcat(char *dst, const char *src,
	size_t dstsize)
{
	unsigned int	r;
	unsigned int	r_copy;
	int				b;
	int				x;

	b = 0;
	r = ft_strlen(dst);
	r_copy = r;
	x = ft_strlen(src);
	if (dstsize == 0 || dstsize < r)
		return (x + dstsize);
	while (src[b] && r < dstsize - 1)
	{
		dst[r] = src[b];
		b++;
		r++;
	}
	dst[r] = '\0';
	return (r_copy + x);
}
