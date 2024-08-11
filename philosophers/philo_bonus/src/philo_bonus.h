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

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include <semaphore.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <signal.h>
# include <fcntl.h>

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
	sem_t				*forks;
	sem_t				*finished;
	sem_t				*dead;
	sem_t				*meals_eaten_s;
	int					meals_eaten;
	sem_t				*pr;
}	t_p_mx;

enum	ev_print
{
	e_fork = 0,
	ev_eating = 1,
	ev_sleeping = 2,
	ev_thinking = 3,
	e_dead = 4
};

t_msec	ll_timestamp(void);
void	v_usleep(t_msec s);
int		i_atoi(const char *str, int *n);
int		i_atoll(const char *str, t_msec *n);
void	v_forking_process(t_p_mx *philos, t_p *a, int i);
int		semphonize(t_p_mx *philos, t_p *a);
void	v_print(t_p_mx *m, enum ev_print print);
int		is_finished(t_p_mx *m);
int		initialization(int ac, char **av, t_p *a);
int		i_scheduler(t_p_mx *m);
void	*simulation(t_p_mx *m);
void	create_philo_process(t_p_mx *philos, t_p *a);
void	v_end_child(t_p *a);
void	*check_death(void *m);
void	v_error_msg(void);
void	v_eating(t_p_mx *m);
void	v_sleeping(t_p_mx *m);
void	v_thinking(t_p_mx *m);
void	v_dying(t_p_mx *m);

#endif