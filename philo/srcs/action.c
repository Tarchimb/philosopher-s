/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 10:45:49 by tarchimb          #+#    #+#             */
/*   Updated: 2022/03/09 13:13:30 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

/*
	print the sleeping message and sleep time needed
*/
void	sleeping(t_philo *philo)
{
	if (is_alive(philo) == TRUE)
	{
		talk(philo, SLEEP);
		my_sleep(philo->time_to_sleep * 1000);
	}
}

/*
	>print the fork message
	>lock and unlock fork with mutex
	>call eating function
*/
void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	if (is_alive(philo) == TRUE)
		talk(philo, FORK);
	if (philo->number_of_philo > 1)
		pthread_mutex_lock(philo->right_fork);
	else
	{
		pthread_mutex_lock(&philo->mutex_alive);
		philo->alive = 0;
		pthread_mutex_unlock(&philo->mutex_alive);
	}
	if (is_alive(philo) == TRUE)
		talk(philo, FORK);
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
	if (is_alive(philo) == TRUE)
	{
		pthread_mutex_lock(&philo->mutex_last_meal);
		gettimeofday(&philo->last_meal, NULL);
		pthread_mutex_unlock(&philo->mutex_last_meal);
		talk(philo, EAT);
		my_sleep(philo->time_to_eat * 1000);
		pthread_mutex_lock(&philo->mutex_numbers_of_eats_needed);
		if (philo->numbers_of_eats_needed != -1)
			philo->numbers_of_eats_needed -= 1;
		pthread_mutex_lock(&philo->mutex_alive);
		if (philo->numbers_of_eats_needed == 0)
			philo->alive = 0;
		pthread_mutex_unlock(&philo->mutex_alive);
		pthread_mutex_unlock(&philo->mutex_numbers_of_eats_needed);
	}
}

/*
	print the thinking message and sleep time needed
*/
void	thinking(t_philo *philo)
{
	if (is_alive(philo) == TRUE)
		talk(philo, THINK);
}

/*
	>print the dying message and sleep time needed
	>set alive variable to 0 in order to stop the program
*/
void	died(t_prg *prg, int i)
{
	int	j;

	j = -1;
	while (++j < prg->numbers_of_philo)
	{
		pthread_mutex_lock(&prg->philo[j].mutex_alive);
		prg->philo[j].alive = 0;
		pthread_mutex_unlock(&prg->philo[j].mutex_alive);
	}
	my_sleep(800);
	talk(&prg->philo[i], DIE);
}
