/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 07:59:25 by tarchimb          #+#    #+#             */
/*   Updated: 2022/03/01 14:10:22 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

long	new_time(struct timeval start)
{
	struct timeval	end;

	gettimeofday(&end, NULL);
	return (((end.tv_sec - start.tv_sec) + 1e-6
			* (end.tv_usec - start.tv_usec)) * 1000);
}

int	take_fork_odd(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->mutex) == 0 && philo->alive == 1)
	{
		take_fork(philo, FALSE);
		if (pthread_mutex_lock(philo->mutex_right) == 0)
		{
			take_fork(philo, TRUE);
			eating(philo);
		}
	}
	pthread_mutex_unlock(&philo->mutex);
	pthread_mutex_unlock(philo->mutex_right);
	return (0);
}

int	take_fork_even(t_philo *philo)
{
	if (pthread_mutex_lock(philo->mutex_right) == 0 && philo->alive == 1)
	{
		take_fork(philo, FALSE);
		if (pthread_mutex_lock(&philo->mutex) == 0)
		{
			take_fork(philo, TRUE);
			eating(philo);
		}
	}
	pthread_mutex_unlock(philo->mutex_right);
	pthread_mutex_unlock(&philo->mutex);
	return (0);
}

void	*routine(void *philo_n)
{
	t_philo			*philo;

	philo = (t_philo *)philo_n;
	gettimeofday(&philo->start, NULL);
	// if (philo->philo_position % 2 == 0)
	// 	usleep(1000);
	while (philo->alive == 1 && philo->numbers_of_eats_needed != 0)
	{
		if (philo->philo_position % 2 == 0)
			take_fork_even(philo);
		else
			take_fork_odd(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (philo_n);
}

/*
	Check during the whole simulation if time_to_die is still superior to 0
	or number of eats_needed == 0
	If no, stop threadsand stop program
*/
int	is_alive(t_prg *prg)
{
	int	i;

	i = 0;
	while (i < prg->numbers_of_philo
		&& prg->philo[i].numbers_of_eats_needed != 0)
	{
		if (prg->philo[i].time_to_die < new_time(prg->philo[i].last_meal))
		{
			died(prg, i);
			break ;
		}
		i++;
		if (i == prg->numbers_of_philo)
			i = 0;
	}
	i = 0;
	while (++i < prg->numbers_of_philo)
		if (pthread_join(prg->philo[i].philo, NULL) != 0)
			return (print_stderror(0, strerror(errno)));
	return (1);
}

/*
	control function for threads :
		>start simulation
		>create threads
		>init mutex and assign it to philosopher's
		>close simulation when needed
*/
int	start_simulation(t_prg *prg)
{
	int	i;

	i = -1;
	while (++i < prg->numbers_of_philo)
		gettimeofday(&prg->philo[i].last_meal, NULL);
	i = -1;
	while (++i < prg->numbers_of_philo)
		if (pthread_mutex_init(&prg->philo[i].mutex, NULL) != 0)
			return (print_stderror(-1, strerror(errno)));
	i = -1;
	while (++i < prg->numbers_of_philo - 1)
		prg->philo[i].mutex_right = &prg->philo[i + 1].mutex;
	prg->philo[i].mutex_right = &prg->philo[0].mutex;
	i = -1;
	while (++i < prg->numbers_of_philo)
		if (pthread_create(&prg->philo[i].philo, NULL, &routine
				, &prg->philo[i]) != 0)
			return (print_stderror(0, strerror(errno)));
	i = -1;
	is_alive(prg);
	free(prg->philo);
	return (1);
}
