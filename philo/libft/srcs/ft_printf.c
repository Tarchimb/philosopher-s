/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 09:49:01 by mliboz            #+#    #+#             */
/*   Updated: 2021/12/10 15:41:04 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
	1: Get the index of the arg corresponding to the index of 
	   the pointer to functions
	2: If the arg is valid and not a % print the arg
	3: If the arg is valid and it's a % print %
	4: Return the total of chars print 
*/
static int	ft_print_arg(char arg, va_list args, int fd)
{
	void	*argument;

	argument = va_arg(args, void *);
	if (arg == 'c')
		return (ft_putchar_fd((char)argument, fd));
	if (arg == 's')
		return (ft_putstr_fd((char *)argument, fd));
	if (arg == 'p')
		return (ft_putptr_fd((unsigned long)argument, fd));
	if (arg == 'd' || arg == 'i')
		return (ft_putnbr_fd((int)argument, fd));
	if (arg == 'u')
		return (ft_putunbr_fd((unsigned int)argument, fd));
	if (arg == 'x' && (unsigned int)argument != 0)
		return (ft_convert_base_fd((unsigned int)argument, BASE16,
				ft_strlen(BASE16), fd));
	if (arg == 'X' && (unsigned int)argument != 0)
		return (ft_convert_base_fd((unsigned int)argument, BASE_U16,
				ft_strlen(BASE_U16), fd));
	if ((arg == 'x' || arg == 'X') && (unsigned int)argument == 0)
		return (ft_putchar_fd('0', fd));
	if (arg == '%')
		return (ft_putchar_fd('%', fd));
	return (0);
}

/*
	1: Start the list
	2: If there is % print the arg
	3: Else print the char
	4: End the list
	5: All the functions that print something return the number of chars
	   they print, everything is add up and return.
*/
int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			i;
	int			return_value;

	return_value = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			return_value += ft_print_arg(str[i++ + 1], args, 1);
		else
			return_value += ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(args);
	return (return_value);
}
