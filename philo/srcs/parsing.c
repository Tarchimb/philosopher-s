/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 21:14:08 by tarchimb          #+#    #+#             */
/*   Updated: 2022/02/12 16:30:48 by tarchimb         ###   ########.fr       */
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
			if (argv[i][j] == '+')
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
	philo->philo_position = i + 1;
	philo->numbers_of_philo = first.numbers_of_philo;
	philo->numbers_of_eats_needed = first.numbers_of_eats_needed;
	philo->philo_position = i + 1;
	philo->time_to_die = ft_atoi(argv[2]);
	if (!philo->time_to_die)
		return (FALSE);
	philo->time_to_eat = ft_atoi(argv[3]);
	if (!philo->time_to_eat)
		return (FALSE);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (!philo->time_to_sleep)
		return (FALSE);
	return (TRUE);
}

/*
	Malloc table.philo
	Get numbers of philo and then call init_philo
*/
t_philo	*parsing(int argc, char **argv, int *error)
{
	t_philo	*table;
	int		i;

	i = -1;
	if (!syntax_arg(argv + 1))
	{
		*error = -1;
		print_stderror(-1, "Please enter positive numbers");
		return (0);
	}
	table = malloc(sizeof(t_philo *) * ft_atoi(argv[1]));
	if (!table)
	{
		*error = -1;
		print_stderror(0, strerror(errno));
		return (0);
	}
	table[0].numbers_of_philo = ft_atoi(argv[1]);
	if (table[0].numbers_of_philo <= 0)
	{
		print_stderror(-1, "need at least 1 philosopher's");
		return (0);
	}
	if (argc == 6)
	{
		table[0].numbers_of_eats_needed = ft_atoi(argv[5]);
		if (table[0].numbers_of_eats_needed == 0)
			return (0);
	}
	else
		table[0].numbers_of_eats_needed = -1;
	while (++i < table[0].numbers_of_philo)
	{
		if (!init_philo(&table[i], i, argv, table[0]))
		{
			print_stderror(0, "time need to be superior to 0");
			return (0);
		}
	}
	return (table);
}
