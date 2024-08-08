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

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>
# include <limits.h>

typedef struct s_philo
{
	int					n;
	int					m_count;
	bool				is_eating;
	pthread_t			thread;
	long int			last_ate;
	struct s_info		*info;
	pthread_mutex_t		*fork_r;
	pthread_mutex_t		fork_l;
}t_philo;

typedef struct s_info
{
	int					p_eat;
	int					n_philo;
	int					t_die;
	int					t_eat;
	int					t_sleep;
	int					nx_eat;
	int					stop;
	long int			t_start;
	t_philo				*philo;
	pthread_mutex_t		print;
	pthread_mutex_t		m_stop;
	pthread_mutex_t		m_eat;
	pthread_mutex_t		dead;
}t_info;

void				display_error(void);
int				is_digit(char c);
int				is_num(char **av);
int				var_init(t_info *data, char **av);
int				philo_init(t_info *data);
int				is_dead(t_philo *philo, int np);
int				ft_atoi(char *s);
long long		timestamp(void);
void			ft_usleep(int ms);
void			free_all(t_info *data);
void			print(t_philo *philo, char *s);
void			*check_death(void *p);
void			take_fork(t_philo *philo);
void			philo_eat(t_philo *philo);
void			*philo_life(void *p);
#endif
