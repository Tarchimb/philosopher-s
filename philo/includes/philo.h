/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:45:00 by tarchimb          #+#    #+#             */
/*   Updated: 2022/03/06 22:25:29 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>
# include <limits.h>

# define TRUE 1
# define FALSE 0
# define EXIT_S 1
# define EXIT_F 0

typedef struct s_philo
{
	pthread_t		philo;
	int				philo_position;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				numbers_of_eats_needed;
	int				number_of_philo;
	int				alive;
	int				eating;
	pthread_mutex_t	mutex;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	mutex_numbers_of_eats_needed;
	pthread_mutex_t	mutex_alive;
	pthread_mutex_t	mutex_last_meal;
	pthread_mutex_t	mutex_start;
	struct timeval	last_meal;
	struct timeval	end;
	struct timeval	start;
}	t_philo;

typedef struct s_prg
{
	t_philo	*philo;
	int		time_to_die;
	int		numbers_of_philo;
}	t_prg;

/*****************Parsing******************/

int		parsing(int argc, char **argv, t_prg *prg);

/******************Utils*******************/

int		print_stderror(int error, char *s1);
void	ft_free(void **content);
long	new_time(struct timeval start);
void	my_sleep(int to_sleep);
int		destroy_mutex(t_prg *prg);
int		is_died(t_prg *prg, int i);
int		is_alive(t_prg *prg);

/******************Action*******************/

void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);
void	eating(t_philo *philo);
void	take_fork(t_philo *philo);
void	died(t_prg *prg, int i);

/***********libft function's***************/

int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);
int		ft_putstr_fd(char *s, int fd);
int		ft_strlen(const char *s);

/****************Simulation****************/
int		start_simulation(t_prg *prg);

#endif