/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 10:45:49 by tarchimb          #+#    #+#             */
/*   Updated: 2022/03/04 15:25:51 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

/*
	print the sleeping message and sleep time needed
*/
void	sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex_alive);
	if (philo->alive == 1)
	{
		pthread_mutex_unlock(&philo->mutex_alive);
		pthread_mutex_lock(&philo->mutex_start);
		printf("%ld %d is sleeping\n", new_time(philo->start),
			philo->philo_position);
		pthread_mutex_unlock(&philo->mutex_start);
		my_sleep(philo->time_to_sleep * 1000);
	}
	pthread_mutex_unlock(&philo->mutex_alive);
}

/*
	>print the fork message
	>lock and unlock fork with mutex
	>call eating function
*/
void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(&philo->mutex_alive);
	if (philo->alive == 1)
	{
		pthread_mutex_lock(&philo->mutex_start);
		printf("%ld %d has taken a fork\n", new_time(philo->start),
			philo->philo_position);
		pthread_mutex_unlock(&philo->mutex_start);
	}
	pthread_mutex_unlock(&philo->mutex_alive);
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(&philo->mutex_alive);
	if (philo->alive == 1)
	{
		pthread_mutex_lock(&philo->mutex_start);
		printf("%ld %d has taken a fork\n", new_time(philo->start),
			philo->philo_position);
		pthread_mutex_unlock(&philo->mutex_start);
	}
	pthread_mutex_unlock(&philo->mutex_alive);
	eating(philo);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

/*
	>print the eating message and sleep time needed
	>reinit last_meal struct
*/
void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex_alive);
	if (philo->alive == 1)
	{
		pthread_mutex_unlock(&philo->mutex_alive);
		pthread_mutex_lock(&philo->mutex_last_meal);
		gettimeofday(&philo->last_meal, NULL);
		pthread_mutex_unlock(&philo->mutex_last_meal);
		philo->eating = 1;
		pthread_mutex_lock(&philo->mutex_start);
		printf("%ld %d is eating\n", new_time(philo->start),
			philo->philo_position);
		pthread_mutex_unlock(&philo->mutex_start);
		my_sleep(philo->time_to_eat * 1000);
		philo->eating = 0;
		pthread_mutex_lock(&philo->mutex_numbers_of_eats_needed);
		if (philo->numbers_of_eats_needed != -1)
			philo->numbers_of_eats_needed -= 1;
		pthread_mutex_lock(&philo->mutex_alive);
		if (philo->numbers_of_eats_needed == 0)
			philo->alive = 0;
		pthread_mutex_unlock(&philo->mutex_alive);
		pthread_mutex_unlock(&philo->mutex_numbers_of_eats_needed);
	}
	pthread_mutex_unlock(&philo->mutex_alive);
}

/*
	print the thinking message and sleep time needed
*/
void	thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex_alive);
	if (philo->alive == 1)
	{
		pthread_mutex_lock(&philo->mutex_start);
		printf("%ld %d is thinking\n", new_time(philo->start),
			philo->philo_position);
		pthread_mutex_unlock(&philo->mutex_start);
	}
	pthread_mutex_unlock(&philo->mutex_alive);
}

/*
	>print the dying message and sleep time needed
	>set alive variable to 0 in order to stop the program
*/
void	died(t_prg *prg, int i)
{
	int	j;

	j = -1;
	(void)i;
	while (++j < prg->numbers_of_philo)
	{
		pthread_mutex_lock(&prg->philo[j].mutex_alive);
		prg->philo[j].alive = 0;
		pthread_mutex_unlock(&prg->philo[j].mutex_alive);
	}
	my_sleep(100);
	pthread_mutex_lock(&prg->philo[i].mutex_start);
	printf("%ld %d died\n", new_time(prg->philo[i].start),
		prg->philo[i].philo_position);
	pthread_mutex_unlock(&prg->philo[i].mutex_start);
}
