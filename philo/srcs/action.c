/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 10:45:49 by tarchimb          #+#    #+#             */
/*   Updated: 2022/03/02 16:45:42 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

/*
	print the sleeping message and sleep time needed
*/
void	sleeping(t_philo *philo)
{
	if (philo->alive == 1)
	{
		printf("%ld %d is sleeping\n", new_time(philo->start),
			philo->philo_position);
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
	pthread_mutex_lock(&philo->left_fork);
	if (philo->alive == 1)
		printf("%ld %d has taken a fork\n", new_time(philo->start),
			philo->philo_position);
	pthread_mutex_lock(philo->right_fork);
	if (philo->alive == 1)
		printf("%ld %d has taken a fork\n", new_time(philo->start),
			philo->philo_position);
	eating(philo);
	pthread_mutex_unlock(&philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

/*
	>print the eating message and sleep time needed
	>reinit last_meal struct
*/
void	eating(t_philo *philo)
{
	if (philo->alive == 1)
	{
		gettimeofday(&philo->last_meal, NULL);
		philo->eating = 1;
		printf("%ld %d is eating\n", new_time(philo->start),
			philo->philo_position);
		my_sleep(philo->time_to_eat * 1000);
		philo->eating = 0;
		if (philo->numbers_of_eats_needed != -1)
			philo->numbers_of_eats_needed -= 1;
	}
}

/*
	print the thinking message and sleep time needed
*/
void	thinking(t_philo *philo)
{
	if (philo->alive == 1)
		printf("%ld %d is thinking\n", new_time(philo->start),
			philo->philo_position);
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
		prg->philo[j].alive = 0;
	usleep(1000);
	printf("%ld %d died\n", new_time(prg->philo[i].start),
		prg->philo[i].philo_position);
}
