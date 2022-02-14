/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 09:49:34 by mliboz            #+#    #+#             */
/*   Updated: 2021/12/10 15:39:02 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
	Convert a number to hexa, print it and assign to pointer i the number of
	chars print
*/
int	ft_convert_base_fd(unsigned long nbr, char *base, int baselen, int fd)
{
	int		i;

	i = 0;
	if (nbr != 0)
		i += ft_convert_base_fd(nbr / baselen, base, baselen, fd);
	if (nbr < 0)
		i += ft_putchar_fd(base[-(nbr % baselen)], fd);
	else if (nbr != 0)
		i += ft_putchar_fd(base[nbr % baselen], fd);
	return (i);
}
