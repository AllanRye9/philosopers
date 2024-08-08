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
# include <stdbool.h>
# include <signal.h>
# include <fcntl.h>

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
	sem_t				*forks;
	sem_t				*finished;
	sem_t				*dead;
	sem_t				*times_eaten_s;
	int					times_eaten;
	sem_t				*pr;
}	t_philo_m;

enum	e_print {
	e_fork = 0,
	e_eating = 1,
	e_sleeping = 2,
	e_thinking = 3,
	e_dead = 4
};

int				my_atoi(const char *str, int *n);
int				var_init(int ac, char **av, t_philo_p *args);
int				ft_table(t_philo_m *m);
int				is_finished(t_philo_m *m);
int				my_atoll(const char *str, t_msec *n);
int				philo_init(t_philo_m *philos, t_philo_p *args);
t_msec			timestamp(void);
void			*check_death(void *m);
void			ft_eating(t_philo_m *m);
void			ft_sleeping(t_philo_m *m);
void			display_error(void);
void			ft_thinking(t_philo_m *m);
void			ft_usleep(t_msec ms);
void			ft_dying(t_philo_m *m);
void			philo_r_wait(t_philo_p *args);
void			*philo_routine(t_philo_m *m);
void			init_philos(t_philo_m *philos, t_philo_p *args, int i);
void			philo_create(t_philo_m *philos, t_philo_p *args);
void			init_philos(t_philo_m *philos, t_philo_p *args, int i);
void			ft_printing(t_philo_m *m, enum e_print print);
#endif
