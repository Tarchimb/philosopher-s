/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 07:59:25 by tarchimb          #+#    #+#             */
/*   Updated: 2022/03/02 16:42:04 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

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
	if (philo->philo_position % 2 == 0)
		usleep(1000);
	while (philo->alive == 1 && philo->numbers_of_eats_needed != 0)
	{
		take_fork(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (philo_n);
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
	while (i < prg->numbers_of_philo
		&& prg->philo[i].numbers_of_eats_needed != 0)
	{
		if (new_time(prg->philo[i].last_meal) >= prg->philo[i].time_to_die
			&& prg->philo[i].eating == 0)
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
		if (pthread_mutex_init(&prg->philo[i].left_fork, NULL) != 0)
			return (print_stderror(-1, strerror(errno)));
	i = -1;
	while (++i < prg->numbers_of_philo - 1)
		prg->philo[i].right_fork = &prg->philo[i + 1].left_fork;
	prg->philo[i].right_fork = &prg->philo[0].left_fork;
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
