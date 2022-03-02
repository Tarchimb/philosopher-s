/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:35:55 by tarchimb          #+#    #+#             */
/*   Updated: 2022/03/02 16:41:36 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

/*
	my_sleep is used for a better accurency of the sleeping time of the program
*/
void	my_sleep(int to_sleep)
{
	struct timeval	start_time;
	int				i;

	i = 2;
	gettimeofday(&start_time, NULL);
	while (new_time(start_time) < (to_sleep / 1000))
	{
		if ((to_sleep / 100 / i) > 100)
			usleep(to_sleep / 100 / i);
		else
		{
			i /= 2;
			usleep(to_sleep / 100 / i);
		}
		i *= 2;
	}
}

/*
	calculate the time spend since the start of the simulation
*/
long	new_time(struct timeval start)
{
	struct timeval	end;

	gettimeofday(&end, NULL);
	return (((end.tv_sec - start.tv_sec) + 1e-6
			* (end.tv_usec - start.tv_usec)) * 1000);
}
