/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:45:00 by tarchimb          #+#    #+#             */
/*   Updated: 2022/02/12 16:25:25 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <libft.h>
# include <unistd.h>
# include <errno.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define TRUE 1
# define FALSE 0
# define EXIT_S 1
# define EXIT_F 0

typedef struct s_philo
{
	pthread_t	philo;
	int			philo_position;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			numbers_of_philo;
	int			numbers_of_eats_needed;
	int			available_fork;
}	t_philo;

/*****************Parsing******************/

t_philo	*parsing(int argc, char **argv, int *error);

/******************Utils*******************/

int		print_stderror(int error, char *s1);
void	ft_free(void **content);
long	get_time(void);

/****************Simulation****************/
// int		start_simulation(t_thread *t);

#endif