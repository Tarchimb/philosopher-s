/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:23:16 by mliboz            #+#    #+#             */
/*   Updated: 2021/11/29 09:26:50 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	ft_intlen(int n)
{
	int		count;

	count = 0;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static void	ft_recursive(int n, char *dst, int *i)
{
	if (n < -9 || n > 9)
	{
		ft_recursive(n / 10, dst, i);
	}
	if (n < 0)
	{
		dst[*i] = -(n % 10) + '0';
		*i += 1;
	}
	else
	{
		dst[*i] = (n % 10) + '0';
		*i += 1;
	}
}

char	*ft_itoa(int n)
{
	char	*dst;
	int		nlen;
	int		neg;
	int		i;

	neg = 0;
	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	nlen = ft_intlen(n) + 1;
	if (n < 0)
		neg = +1;
	dst = malloc(sizeof(char) * (nlen + neg));
	if (!dst)
		return (0);
	if (n < 0)
	{
		dst[0] = '-';
		i = 1;
	}
	ft_recursive(n, dst, &i);
	dst[i] = 0;
	return (dst);
}
