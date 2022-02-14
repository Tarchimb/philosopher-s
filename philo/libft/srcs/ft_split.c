/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:09:27 by mliboz            #+#    #+#             */
/*   Updated: 2022/01/06 14:07:58 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	ft_count_words(const char *str, char charset)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (str[i] && str[i] == charset)
		i++;
	if (str[i] != 0)
		count++;
	while (str[i])
	{
		if (str[i] == charset
			&& (str[i + 1] != charset && str[i + 1] != 0))
			count++;
		i++;
	}
	return (count);
}

static char	*ft_copy(const char *src, char c, int *i)
{
	int		end;
	char	*dst;
	int		size;

	while (src[*i] == c)
		*i += 1;
	end = *i;
	while (src[end] != c && src[end])
		end++;
	size = end - *i;
	dst = ft_substr(src, *i, size);
	*i = end;
	return (dst);
}

static char	**ft_free(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	int		words;
	int		i;
	int		dsti;

	if (!s)
		return (0);
	i = 0;
	dsti = 0;
	words = ft_count_words(s, c);
	if (!s)
		return (0);
	dst = malloc(sizeof(char *) * (words + 1));
	if (!dst)
		return (0);
	while (words--)
	{
		dst[dsti] = ft_copy(s, c, &i);
		if (!dst[dsti])
			return (ft_free(dst));
		dsti++;
	}
	dst[dsti] = 0;
	return (dst);
}
