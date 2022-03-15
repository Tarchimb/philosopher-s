/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 10:45:49 by tarchimb          #+#    #+#             */
/*   Updated: 2022/03/15 17:44:20 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

/*
	launch an infinite loop, while philosophers are still alive and didn't 
	took they're to forks.
*/
void	take_fork(t_philo *philo)
{
	while (is_alive(philo) == TRUE && philo->got_forks != 1)
	{
		pthread_mutex_lock(&philo->left_fork.mutex_fork);
		if (philo->left_fork.is_available == true)
		{
			philo->left_fork.is_available = false;
			talk(philo, FORK);
			while (is_alive(philo) == TRUE && philo->got_forks != 1)
			{
				pthread_mutex_lock(&philo->right_fork->mutex_fork);
				if (philo->right_fork->is_available == true)
				{
					philo->right_fork->is_available = false;
					philo->got_forks = 1;
					talk(philo, FORK);
				}
				pthread_mutex_unlock(&philo->right_fork->mutex_fork);
				usleep(100);
			}
		}
		pthread_mutex_unlock(&philo->left_fork.mutex_fork);
		usleep(100);
	}
}

/*
	>print the eating message and sleep time needed
	>reinit last_meal struct
*/
void	eating(t_philo *philo)
{
	if (is_alive(philo) == TRUE)
	{
		gettimeofday(&philo->last_meal, NULL);
		talk(philo, EAT);
		my_sleep(philo, philo->time_to_eat * 1000);
		if (philo->numbers_of_eats_needed != -1)
			philo->numbers_of_eats_needed -= 1;
	}
}

/*
	print the sleeping message and sleep time needed
*/
void	sleeping(t_philo *philo)
{
	if (is_alive(philo) == TRUE)
	{
		talk(philo, SLEEP);
		pthread_mutex_lock(&philo->left_fork.mutex_fork);
		philo->left_fork.is_available = true;
		pthread_mutex_unlock(&philo->left_fork.mutex_fork);
		pthread_mutex_lock(&philo->right_fork->mutex_fork);
		philo->right_fork->is_available = true;
		philo->got_forks = 0;
		pthread_mutex_unlock(&philo->right_fork->mutex_fork);
		my_sleep(philo, philo->time_to_sleep * 1000);
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
	print the message asked by msg
*/
void	talk(t_philo *philo, int msg)
{
	pthread_mutex_lock(philo->mutex_alive);
	if (msg == DIE && *philo->alive == true)
	{
		*philo->alive = false;
		printf("%ld %d died\n", new_time(philo->start),
			philo->philo_position);
		usleep(1000);
	}
	if (*philo->alive == true && philo->numbers_of_eats_needed != 0)
	{
		if (msg == EAT)
			printf("%ld %d is eating\n", new_time(philo->start),
				philo->philo_position);
		else if (msg == THINK)
			printf("%ld %d is thinking\n", new_time(philo->start),
				philo->philo_position);
		else if (msg == SLEEP)
			printf("%ld %d is sleeping\n", new_time(philo->start),
				philo->philo_position);
		else if (msg == FORK)
			printf("%ld %d has taken a fork\n",
				new_time(philo->start), philo->philo_position);
	}
	pthread_mutex_unlock(philo->mutex_alive);
}
