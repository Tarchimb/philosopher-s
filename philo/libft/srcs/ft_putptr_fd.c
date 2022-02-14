/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 09:25:33 by mliboz            #+#    #+#             */
/*   Updated: 2021/12/10 15:30:18 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
	Print the address of a pointer in hexadecimal and return the number of char
*/
int	ft_putptr_fd(unsigned long ptr, int fd)
{
	int		i;

	i = 2;
	ft_putstr_fd("0x", fd);
	ft_convert_base_fd(ptr, BASE16, ft_strlen(BASE16), fd);
	if (i == 2)
	{
		ft_putchar_fd('0', fd);
		return (i + 1);
	}
	return (i);
}
