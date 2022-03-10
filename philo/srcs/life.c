/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:42:57 by tarchimb          #+#    #+#             */
/*   Updated: 2022/03/10 09:55:51 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

/*
	Lock mutex_alive
	Return if philo->alive is TRUE or FALSE
	Unlock mutex_alive
*/
int	is_alive(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex_alive);
	if (philo->alive == 1)
	{
		pthread_mutex_unlock(&philo->mutex_alive);
		return (TRUE);
	}
	pthread_mutex_unlock(&philo->mutex_alive);
	return (FALSE);
}

/*
	Lock mutex_talk
	print the message asked by msg
	Unlock mutex_talk
*/
void	talk(t_philo *philo, int msg)
{
	pthread_mutex_lock(&philo->mutex_talk);
	if (msg == EAT)
		printf("%ld %d is eating\n", new_time(philo->start),
			philo->philo_position);
	else if (msg == THINK)
		printf("%ld %d is thinking\n", new_time(philo->start),
			philo->philo_position);
	else if (msg == SLEEP)
		printf("%ld %d is sleeping\n", new_time(philo->start),
			philo->philo_position);
	else if (msg == DIE)
		printf("%ld %d died\n", new_time(philo->start),
			philo->philo_position);
	else if (msg == FORK)
		printf("%ld %d has taken a fork\n", new_time(philo->start),
			philo->philo_position);
	pthread_mutex_unlock(&philo->mutex_talk);
}

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
	pthread_mutex_unlock(&prg->philo[i].mutex_numbers_of_eats_needed);
	pthread_mutex_lock(&prg->philo[i].mutex_last_meal);
	if (new_time(prg->philo[i].last_meal) >= prg->time_to_die)
	{
		pthread_mutex_unlock(&prg->philo[i].mutex_last_meal);
		died(prg, i);
		return (0);
	}
	pthread_mutex_unlock(&prg->philo[i].mutex_last_meal);
	return (1);
}

/*
	Check during the whole simulation if time_to_die is still superior to 0
	or number of eats_needed != 0
	If no, stop threads and stop program
*/
int	alive(t_prg *prg)
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
			usleep(100);
		}
	}
	i = -1;
	while (++i < prg->numbers_of_philo)
	{
		if (pthread_join(prg->philo[i].philo, NULL) != 0)
			return (0);
	}
	return (1);
}
