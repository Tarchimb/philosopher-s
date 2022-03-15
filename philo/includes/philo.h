/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:45:00 by tarchimb          #+#    #+#             */
/*   Updated: 2022/03/15 09:23:15 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>

# define TRUE 1
# define FALSE 0
# define EAT 0
# define SLEEP 1
# define THINK 2
# define DIE 3
# define FORK 4

typedef struct s_fork
{
	bool			is_available;
	pthread_mutex_t	mutex_fork;
}	t_fork;

typedef struct s_philo
{
	pthread_t		philo;
	int				philo_position;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				numbers_of_eats_needed;
	int				got_forks;
	bool			*alive;
	t_fork			left_fork;
	t_fork			*right_fork;
	pthread_mutex_t	*mutex_alive;
	struct timeval	last_meal;
	struct timeval	start;
}	t_philo;

typedef struct s_prg
{
	t_philo			*philo;
	bool			alive;
	int				numbers_of_philo;
	pthread_mutex_t	mutex_alive;
}	t_prg;

/*****************Parsing******************/

int		parsing(int argc, char **argv, t_prg *prg);

/******************Utils*******************/

int		print_stderror(int error, char *s1);
void	ft_free(void **content);
long	new_time(struct timeval start);
void	my_sleep(t_philo *philo, int to_sleep);
int		is_died(t_prg *prg, int i);
int		is_alive(t_philo *philo);

/******************Action*******************/

void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);
void	eating(t_philo *philo);
void	take_fork(t_philo *philo);
void	died(t_prg *prg, int i);
void	talk(t_philo *philo, int msg);

/***********libft function's***************/

int		ft_atoi(const char *nptr);
bool	ft_isdigit(int c);
int		ft_putstr_fd(char *s, int fd);
int		ft_strlen(const char *s);

/****************Simulation****************/
int		start_simulation(t_prg *prg);

#endif