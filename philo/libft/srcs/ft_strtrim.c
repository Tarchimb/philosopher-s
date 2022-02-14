/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 09:48:13 by mliboz            #+#    #+#             */
/*   Updated: 2021/11/29 09:26:50 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	int		beg;
	int		end;
	int		size;

	if (!s1 || !set)
		return (0);
	beg = 0;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[beg]))
	{
		if (s1[beg + 1] == '\0')
			return (ft_strdup(""));
		beg++;
	}
	while (ft_strchr(set, s1[end]))
		end--;
	size = end - beg + 1;
	return (ft_substr(s1, beg, size));
}
