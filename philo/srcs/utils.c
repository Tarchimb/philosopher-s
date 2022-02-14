/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 21:47:43 by tarchimb          #+#    #+#             */
/*   Updated: 2022/02/04 09:33:52 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

/*
	Returns the timestamp in milliseconds
*/

long	get_time(void)
{
	struct timeval	tp;
	long			milliseconds;

	gettimeofday(&tp, NULL);
	milliseconds = tp.tv_sec * 1000;
	milliseconds += tp.tv_usec / 1000;
	return (milliseconds);
}

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

/*
	free all contents received
*/
void	ft_free(void **content)
{
	int	i;

	i = 0;
	while (content[i])
	{
		free(content[i]);
		i++;
	}
	free(content);
}