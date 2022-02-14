/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 21:53:36 by tarchimb          #+#    #+#             */
/*   Updated: 2022/02/12 16:33:14 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	print_philo(t_philo *philo)
{
	int	i;

	i = 0;
	printf("Numbers of philo --> %d, needed eating --> %d \n\n", philo[0].numbers_of_philo, philo[0].numbers_of_eats_needed);
	while (i < philo->numbers_of_philo)
	{
		printf("philo position --> %d, time_to_die --> %d, time_to_eat --> %d, time_to_sleep --> %d\n", philo[i].philo_position, philo[i].time_to_die, philo[i].time_to_eat, philo[i].time_to_sleep);
		i++;
	}
}

/*
	Main function
*/
int	main(int argc, char **argv)
{
	t_philo		*t;
	int			error;
	// long		time;
	// int			i = 1;
	// char		*buf;
	// struct	timeval r;

	if (argc < 5 || argc > 6)
		return (printf("Syntax error\n"));
	t = parsing(argc, argv, &error);
	if (error == 0 || error == -1)
	{
		if (error == 0)
			free(t);
		return (0);
	}
	// time = get_time();
	// while (1)
	// {
	// 	usleep(1 * 1000);
	// 	if (get_time() - time >= i * 200)
	// 	{
	// 		printf("%ld\n", get_time() - time);
	// 		i++;
	// 	}
	// }
	start_simulation(&t);
	print_philo(t);
	free(t);
	return (EXIT_SUCCESS);
}
