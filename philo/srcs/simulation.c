/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 07:59:25 by tarchimb          #+#    #+#             */
/*   Updated: 2022/02/12 16:38:57 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	*routine(void *philo)
{
	t_philo			*r;
	int				i;
	pthread_mutex_t	*fork;

	r = (t_philo *)philo;
	i = 0;
	fork = malloc(sizeof(pthread_mutex_t) * r->numbers_of_philo);
	if (!fork)
		return (NULL);
	while (++i < r->numbers_of_philo)
		if (pthread_mutex_init(&fork[i], NULL))
			return (print_stderror(0, strerror(errno)));
	while (1)
	{
		pthread_mutex_lock(&fork[i]);
	}
}

/*
	control function for threads :
		>start simulation
		>create threads
*/
int	start_simulation(t_philo *table)
{
	int	time;
	int	i;

	i = -1;
	time = 0;
	i = -1;
	while (++i < table->numbers_of_philo)
		if (pthread_create(table[i].philo, NULL, &routine
				, &table[i]) != 0)
			return (print_stderror(0, strerror(errno)));
	i = -1;
	while (++i < table->numbers_of_philo)
		if (pthread_join(table[i].philo, NULL) != 0)
			return (print_stderror(0, strerror(errno)));
	return (1);
}