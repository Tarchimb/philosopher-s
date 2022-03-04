/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 21:14:08 by tarchimb          #+#    #+#             */
/*   Updated: 2022/03/04 15:49:48 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

/*
	Check if args are only digits
*/
static int	syntax_arg(char **argv)
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
			if (!ft_isdigit((int)argv[i][j]))
				return (FALSE);
			j++;
		}
		i++;
		j = 0;
	}
	return (TRUE);
}

/*
	Init each philo
*/
static int	init_philo(t_philo *philo, int i, char **argv, t_philo first)
{
	philo->alive = 1;
	philo->philo_position = i + 1;
	philo->eating = 0;
	philo->numbers_of_eats_needed = first.numbers_of_eats_needed;
	philo->time_to_die = ft_atoi(argv[2]);
	if (!philo->time_to_die)
		return (print_stderror(0, "time_to_die need to be superior to 0"));
	philo->time_to_eat = ft_atoi(argv[3]);
	if (!philo->time_to_eat)
		return (print_stderror(0, "time_to_eat need to be superior to 0"));
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (!philo->time_to_sleep)
		return (print_stderror(0, "time_to_sleep need to be superior to 0"));
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
	if (!syntax_arg(argv + 1))
		return (print_stderror(-1, "Bad syntax"));
	prg->philo = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	if (!prg->philo)
		return (print_stderror(0, strerror(errno)));
	prg->numbers_of_philo = ft_atoi(argv[1]);
	if (prg->numbers_of_philo <= 0)
		return (print_stderror(0, "need at least 1 philosopher's"));
	if (argc == 6)
	{
		prg->philo[0].numbers_of_eats_needed = ft_atoi(argv[5]);
		if (prg->philo[0].numbers_of_eats_needed == 0)
			return (0);
	}
	else
		prg->philo[0].numbers_of_eats_needed = -1;
	while (++i < prg->numbers_of_philo)
		if (!init_philo(&prg->philo[i], i, argv, prg->philo[0]))
			return (0);
	prg->time_to_die = prg->philo[0].time_to_die;
	return (1);
}
