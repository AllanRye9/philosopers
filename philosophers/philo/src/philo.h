/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oallan <oallan@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 21:38:54 by oallan            #+#    #+#             */
/*   Updated: 2024/08/07 17:39:22 by oallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

typedef long long	t_msec;

typedef struct s_philo_p
{
	int			numofphilo;
	t_msec		timetodie;
	t_msec		timetoeat;
	t_msec		timetosleep;
	t_msec		timeatstart;
	int			numtoeat;
}	t_philo_p;

typedef struct s_philo_m
{
	t_philo_p			*p;
	int					id;
	t_msec				die_time;
	t_msec				eat_time;
	pthread_mutex_t		left_fork;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*first_fork;
	pthread_mutex_t		*secondfork;
	pthread_mutex_t		times_eaten_m;
	int					times_eaten;
	pthread_mutex_t		*pr;
	struct s_philo_run	*data;
}	t_philo_m;

typedef struct s_philo_run
{
	bool			is_dead;
	t_philo_m		*philos;
	pthread_t		*threads;
	int				count;
	pthread_mutex_t	printing;
}	t_philo_run;

enum	e_print {
	e_fork = 0,
	e_eating = 1,
	e_sleeping = 2,
	e_thinking = 3,
	e_dead = 4
};

int				is_digit(char c);
int				is_num(char **av);
int				var_init(t_info *data, char **av);
int				philo_init(t_info *data);
int				is_dead(t_philo *philo, int np);
int				ft_atoi(char *s);
long long		timestamp(void);
void			display_error(void);
void			ft_usleep(int ms);
void			free_all(t_info *data);
void			print(t_philo *philo, char *s);
void			*check_death(void *p);
void			take_fork(t_philo *philo);
void			philo_eat(t_philo *philo);
void			*philo_life(void *p);
#endif
