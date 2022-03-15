/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 07:59:25 by tarchimb          #+#    #+#             */
/*   Updated: 2022/03/15 13:44:53 by tarchimb         ###   ########.fr       */
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
	if (new_time(philo->last_meal) >= philo->time_to_die)
		talk(philo, DIE);
	pthread_mutex_lock(philo->mutex_alive);
	if (*philo->alive == true)
	{
		pthread_mutex_unlock(philo->mutex_alive);
		return (TRUE);
	}
	pthread_mutex_unlock(philo->mutex_alive);
	return (FALSE);
}

/*
	Routine called by threads :
		>Init time of simulation
		>Call action's eating, sleeping, thinking
*/
void	*routine(void *philo_n)
{
	t_philo			*philo;

	philo = (t_philo *)philo_n;
	gettimeofday(&philo->start, NULL);
	philo->last_meal = philo->start;
	if (philo->philo_position % 2 == 0)
		usleep(1000);
	while (is_alive(philo) == TRUE && philo->numbers_of_eats_needed != 0)
	{
		take_fork(philo);
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (philo_n);
}

static int	destroy_mutex(t_prg *prg)
{
	int	i;

	i = 0;
	while (i < prg->numbers_of_philo)
	{
		if (pthread_mutex_destroy(&prg->philo[i].left_fork.mutex_fork) != 0)
			return (-1);
		if (pthread_mutex_destroy(&prg->mutex_alive) != 0)
			return (-1);
		i++;
	}
	return (1);
}

static int	init_mutex(t_prg *prg, int i)
{
	while (++i < prg->numbers_of_philo)
	{
		if (pthread_mutex_init(&prg->philo[i].left_fork.mutex_fork, NULL) != 0)
			return (-1);
		if (pthread_mutex_init(&prg->mutex_alive, NULL) != 0)
			return (-1);
		prg->philo[i].left_fork.is_available = true;
		prg->philo[i].alive = &prg->alive;
		prg->philo[i].mutex_alive = &prg->mutex_alive;
	}
	i = -1;
	while (++i < prg->numbers_of_philo - 1)
		if (i < prg->numbers_of_philo - 1)
			prg->philo[i].right_fork = &prg->philo[i + 1].left_fork;
	prg->philo[i].right_fork = &prg->philo[0].left_fork;
	return (0);
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
	if (init_mutex(prg, i) == -1)
		return (-1);
	i = -1;
	while (++i < prg->numbers_of_philo)
		if (pthread_create(&prg->philo[i].philo, NULL, &routine
				, &prg->philo[i]) != 0)
			return (0);
	i = -1;
	while (++i < prg->numbers_of_philo)
		if (pthread_join(prg->philo[i].philo, NULL) != 0)
			return (0);
	if (destroy_mutex(prg) == -1)
		return (0);
	return (1);
}
