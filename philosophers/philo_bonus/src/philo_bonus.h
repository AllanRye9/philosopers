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
	int			numtoeat;
}	t_p;

typedef struct s_philo_m
{
	t_p					*p;
	int					id;
	t_msec				die_time;
	sem_t				*forks;
	sem_t				*finished;
	sem_t				*dead;
	sem_t				*times_eaten_s;
	int					times_eaten;
	sem_t				*pr;
}	t_p_mx;

enum	e_print {
	e_fork = 0,
	e_eating = 1,
	e_sleeping = 2,
	e_thinking = 3,
	e_dead = 4
};

t_msec	timestamp(void);
void	ft_usleep(t_msec waiting_time);
int		my_atoi(const char *str, int *n);
int		my_atoll(const char *str, t_msec *n);
void	init_philos(t_p_mx *philos, t_p *args, int i);
int		semphonize(t_p_mx *philos, t_p *args);
void	ft_printing(t_p_mx *m, enum e_print print);
int		is_finished(t_p_mx *m);
int		initialization(int ac, char **av, t_p *args);
int		ft_table(t_p_mx *m);
void	*schedule(t_p_mx *m);
void	create_philo(t_p_mx *philos, t_p *args);
void	philo_r_wait(t_p *args);
void	*check_death(void *m);
void	usage(void);
void	ft_eating(t_p_mx *m);
void	ft_sleeping(t_p_mx *m);
void	ft_thinking(t_p_mx *m);
void	ft_dying(t_p_mx *m);

#endif