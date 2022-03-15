/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 21:14:08 by tarchimb          #+#    #+#             */
/*   Updated: 2022/03/12 00:18:02 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

/*
	Check if args are only digits
*/
static bool	syntax_arg(char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (argv[i][0] == '+')
				j++;
			if (ft_isdigit((int)argv[i][j]) == false)
				return (false);
			j++;
		}
		i++;
		j = 0;
	}
	return (true);
}

/*
	Init each philo
*/
static int	init_philo(t_philo *philo, int i, char **argv, int argc)
{
	if (argc == 6)
	{
		philo->numbers_of_eats_needed = ft_atoi(argv[5]);
		if (philo->numbers_of_eats_needed == 0)
			return (0);
	}
	else
		philo->numbers_of_eats_needed = -1;
	philo->philo_position = i + 1;
	philo->got_forks = 0;
	philo->time_to_die = ft_atoi(argv[2]);
	if (!philo->time_to_die)
		return (print_stderror(0, "Please enter a valid time_to_die"));
	philo->time_to_eat = ft_atoi(argv[3]);
	if (!philo->time_to_eat)
		return (print_stderror(0, "Please enter a valid time_to_eat"));
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (!philo->time_to_sleep)
		return (print_stderror(0, "Please enter a valid time_to_sleep"));
	return (TRUE);
}

/*
	Malloc table.philo
	Get numbers of philo and then call init_philo
*/
int	parsing(int argc, char **argv, t_prg *prg)
{
	int		i;

	i = -1;
	if (syntax_arg(argv + 1) == false)
		return (print_stderror(-1, "Bad syntax"));
	prg->philo = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	if (!prg->philo)
		return (print_stderror(0, "Malloc error"));
	prg->numbers_of_philo = ft_atoi(argv[1]);
	if (prg->numbers_of_philo <= 0)
		return (print_stderror(0, "Please enter valid number of philosophers"));
	while (++i < prg->numbers_of_philo)
		if (!init_philo(&prg->philo[i], i, argv, argc))
			return (0);
	prg->alive = true;
	return (1);
}
