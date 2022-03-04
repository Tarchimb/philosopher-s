/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:42:57 by tarchimb          #+#    #+#             */
/*   Updated: 2022/03/04 15:44:37 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

/*
	Lock mutex, check if philo is dead, or if numbers_of_eats_needed == 0
*/
int	is_died(t_prg *prg, int i)
{
	pthread_mutex_lock(&prg->philo[i].mutex_numbers_of_eats_needed);
	if (prg->philo[i].numbers_of_eats_needed == 0)
	{
		pthread_mutex_unlock(&prg->philo[i].mutex_numbers_of_eats_needed);
		return (0);
	}
	else
		pthread_mutex_unlock(&prg->philo[i].mutex_numbers_of_eats_needed);
	pthread_mutex_lock(&prg->philo[i].mutex_last_meal);
	if (new_time(prg->philo[i].last_meal) >= prg->time_to_die)
	{
		pthread_mutex_unlock(&prg->philo[i].mutex_last_meal);
		died(prg, i);
		return (0);
	}
	else
		pthread_mutex_unlock(&prg->philo[i].mutex_last_meal);
	return (1);
}

/*
	Check during the whole simulation if time_to_die is still superior to 0
	or number of eats_needed != 0
	If no, stop threads and stop program
*/
int	is_alive(t_prg *prg)
{
	int	i;

	i = 0;
	while (1)
	{
		if (!is_died(prg, i))
			break ;
		i++;
		if (i == prg->numbers_of_philo)
		{
			i = 0;
			usleep (500);
		}
	}
	i = -1;
	while (++i < prg->numbers_of_philo)
	{
		if (pthread_join(prg->philo[i].philo, NULL) != 0)
			return (print_stderror(0, strerror(errno)));
	}
	return (1);
}
