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
	t_msec		start;
	int			numtoeat;
}	t_p;

typedef struct s_philo_m
{
	t_p			*p;
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
	struct s_p_main	*data;
}	t_p_mx;

typedef struct s_p_main
{
	int				is_dead;
	t_p_mx		*philos;
	pthread_t		*threads;
	int				count;
	pthread_mutex_t	printing;
}	t_p_main;

enum	e_print {
	e_fork = 0,
	e_eating = 1,
	e_sleeping = 2,
	e_thinking = 3,
	e_dead = 4
};

int				my_atoi(const char *str, int *n);
int				var_init(int ac, char **av, t_p *args);
int				ft_table(t_p_mx *m);
int				my_atoll(const char *str, t_msec *n);
int				philo_init(t_p_main *philo_r, t_p *args);
t_msec			timestamp(void);
void			ft_eating(t_p_mx *m);
void			ft_sleeping(t_p_mx *m);
void			display_error(void);
void			ft_thinking(t_p_mx *m);
void			ft_usleep(t_msec ms);
void			ft_dying(t_p_mx *m);
void			*schedule(void *philo);
void			free_all(t_p_main *philo_r);
void			init_philos(t_p_mx *philos, t_p *args, int i);
void			*philo_life(void *p);
void			philo_create(t_p_main *philo_r);
void			philo_join(t_p_main *philo_r);
void			init_philos(t_p_mx *philos, t_p *args, int i);
void			ft_printing(t_p_mx *m, enum e_print print);
#endif
