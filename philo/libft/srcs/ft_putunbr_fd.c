/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:34:21 by mliboz            #+#    #+#             */
/*   Updated: 2021/12/10 15:14:32 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>

int	ft_putunbr_fd(unsigned int n, int fd)
{
	int	i;

	i = 0;
	if (n > 9)
		i += ft_putunbr_fd(n / 10, fd);
	i += ft_putchar_fd(n % 10 + '0', fd);
	return (i);
}
