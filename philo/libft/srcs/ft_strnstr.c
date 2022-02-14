/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 07:59:13 by mliboz            #+#    #+#             */
/*   Updated: 2021/11/29 09:28:45 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		a;
	int		length;

	a = 0;
	length = ft_strlen(needle);
	if (*needle == 0 || (haystack == needle && length == (int)len))
		return ((char *)haystack);
	if (len == 0)
		return (0);
	while (len-- && haystack[a])
	{
		if (haystack[a] == needle[0])
		{
			if (length > (int)len)
				length = len;
			if (ft_strncmp(haystack + a, needle, length) == 0
				&& needle[length] == 0)
				return ((char *)haystack + a);
		}
		a++;
	}
	return (0);
}
