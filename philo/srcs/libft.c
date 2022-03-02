/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:15:15 by tarchimb          #+#    #+#             */
/*   Updated: 2022/02/28 14:23:52 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	ft_checkstr(const char *str, int *neg, int *str_i)
{
	while (str[*str_i] && (str[*str_i] != '-' && str[*str_i] != '+')
		&& (str[*str_i] < '0' || str[*str_i] > '9'))
	{
		if ((str[*str_i] != '\t' && str[*str_i] != '\n' && str[*str_i] != '\v'
				&& str[*str_i] != '\f' && str[*str_i] != '\r'
				&& str[*str_i] != ' '))
			return (1);
		*str_i += 1;
	}
	if (str[*str_i] == '-' || str[*str_i] == '+')
	{
		if (str[*str_i] == '-')
			*neg *= -1;
		*str_i += 1;
	}
	if (str[*str_i] < '0' || str[*str_i] > '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int		neg;
	int		str_i;
	long	nb;

	neg = 1;
	str_i = 0;
	nb = 0;
	if (ft_checkstr(nptr, &neg, &str_i))
		return (0);
	while (nptr[str_i] >= '0' && nptr[str_i] <= '9')
	{
		nb = nb * 10 + (nptr[str_i] - '0');
		str_i++;
	}
	nb *= neg;
	if (nb > INT_MAX || nb < INT_MIN)
		return (0);
	return (nb);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return (0);
	return (write(fd, s, ft_strlen(s)));
}

int	ft_strlen(const char *s)
{
	int		count;

	count = 0;
	if (!s)
		return (0);
	while (s[count] != 0)
		count++;
	return (count);
}

