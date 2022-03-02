/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 21:53:36 by tarchimb          #+#    #+#             */
/*   Updated: 2022/03/02 17:07:24 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	print_philo(t_prg *prg)
{
	int	i;

	i = 0;
	printf("Numbers of philo --> %d, needed eating --> %d \n\n", prg->numbers_of_philo, prg->philo[0].numbers_of_eats_needed);
	while (i < prg->numbers_of_philo)
	{
		printf("philo position --> %d, time_to_die --> %d, time_to_eat --> %d, time_to_sleep --> %d\n", prg->philo[i].philo_position, prg->philo[i].time_to_die, prg->philo[i].time_to_eat, prg->philo[i].time_to_sleep);
		i++;
	}
}

/*
	Main function
*/
int	main(int argc, char **argv)
{
	t_prg	prg;
	int		error;

	if (argc < 5 || argc > 6)
		return (printf("Syntax error\n"));
	error = parsing(argc, argv, &prg);
	if (error == 0 || error == -1)
	{
		if (error == 0)
			free(prg.philo);
		return (0);
	}
	start_simulation(&prg);
	// print_philo(&prg);
	return (EXIT_SUCCESS);
}
