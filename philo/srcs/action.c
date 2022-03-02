/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 10:45:49 by tarchimb          #+#    #+#             */
/*   Updated: 2022/03/01 14:04:59 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	sleeping(t_philo *philo)
{
	if (philo->alive == 1)
	{
		printf("%ld %d is sleeping\n", new_time(philo->start),
			philo->philo_position);
		usleep(philo->time_to_sleep * 1000);
	}
}

void	take_fork(t_philo *philo, int action)
{
	if (action == 1)
		gettimeofday(&philo->last_meal, NULL);
	if (philo->alive == 1)
		printf("%ld %d has taken a fork\n", new_time(philo->start),
			philo->philo_position);
}

void	eating(t_philo *philo)
{
	if (philo->alive == 1)
	{
		printf("%ld %d is eating\n", new_time(philo->start),
			philo->philo_position);
		usleep(philo->time_to_eat * 1000);
		if (philo->numbers_of_eats_needed != -1)
			philo->numbers_of_eats_needed -= 1;
	}
}

void	thinking(t_philo *philo)
{
	if (philo->alive == 1)
		printf("%ld %d is thinking\n", new_time(philo->start),
			philo->philo_position);
}

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