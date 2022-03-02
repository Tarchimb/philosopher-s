/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 21:47:43 by tarchimb          #+#    #+#             */
/*   Updated: 2022/03/01 10:42:32 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

/*
	printf error_number to stderr
*/
int	print_stderror(int error, char *s1)
{
	ft_putstr_fd(s1, 2);
	ft_putstr_fd("\n", 2);
	errno = 0;
	return (error);
}