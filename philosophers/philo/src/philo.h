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

typedef long long	t_msec;

typedef struct s_philo_p
{
	int			numofphilo;
	t_msec		timetodie;
	t_msec		timetoeat;
	t_msec		timetosleep;
	t_msec		start;
	int			n_meals_toeat;
}	t_p;

typedef struct s_philo_m
{
	t_p					*p;
	int					id;
	t_msec				die_time;
	t_msec				eat_time;
	pthread_mutex_t		left_fork;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*fork_one;
	pthread_mutex_t		*fork_two;
	pthread_mutex_t		meals_eaten_m;
	int					meals_eaten;
	pthread_mutex_t		*pr;
	struct s_p_main		*data;
}	t_p_mx;

typedef struct s_p_main
{
	int				is_dead;
	t_p_mx			*philos;
	pthread_t		*threads;
	int				count;
	pthread_mutex_t	printing;
}	t_p_main;

enum	ev_print
{
	e_fork = 0,
	ev_eating = 1,
	ev_sleeping = 2,
	ev_thinking = 3,
	e_dead = 4
};

int				i_atoi(const char *str, int *n);
int				i_init_args(int ac, char **av, t_p *a);
int				i_scheduler(t_p_mx *m);
int				i_atoll(const char *str, t_msec *n);
int				i_philo_alloc(t_p_main *p, t_p *a);
t_msec			ll_timestamp(void);
void			v_eating(t_p_mx *m);
void			v_sleeping(t_p_mx *m);
void			v_error(void);
void			v_thinking(t_p_mx *m);
void			v_pause(t_msec ms);
void			v_dying(t_p_mx *m);
void			*simulation(void *philo);
void			v_free_all(t_p_main *p);
void			v_forking(t_p_mx *philos, t_p *a, int i);
void			*philo_life(void *p);
void			v_create_philos(t_p_main *p);
void			v_join_philos(t_p_main *p);
void			v_forking(t_p_mx *philos, t_p *a, int i);
void			v_print(t_p_mx *m, enum ev_print print);
#endif
