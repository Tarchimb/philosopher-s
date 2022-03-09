/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:35:55 by tarchimb          #+#    #+#             */
/*   Updated: 2022/03/09 13:02:08 by tarchimb         ###   ########.fr       */
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
	usleep(to_sleep * 0.95);
	while (new_time(start_time) < (to_sleep / 1000))
		usleep(100);
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
