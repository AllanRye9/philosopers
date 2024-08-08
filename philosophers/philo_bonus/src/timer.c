/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oallan <oallan@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 21:38:59 by oallan            #+#    #+#             */
/*   Updated: 2024/08/07 15:52:50 by oallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_msec	timestamp(void)
{
	struct timeval	t;

	if (gettimeofday(&t, NULL))
		return (-1);
	return (((long long)t.tv_sec * 1000) + ((long long)t.tv_usec / 1000));
}

void	ft_usleep(t_msec ms)
{
	t_msec	t;

	t = timestamp();
	while (ms - t > 5)
	{
		usleep(1000 * (ms - t - 5));
		t = timestamp();
	}
	while (ms > t)
		t = timestamp();
}


void	ft_sleeping(t_philo_m *m)
{
	ft_printing(m, 2);
	ft_usleep(timestamp() + m->p->timetosleep);
}

void	ft_thinking(t_philo_m *m)
{
	ft_printing(m, 3);
}

void	ft_dying(t_philo_m *m)
{
	ft_usleep(m->die_time);
	ft_printing(m, 4);
}

void	philo_r_wait(t_philo_p *args)
{
	int	i;

	i = 0;
	while (i < args->numofphilo)
	{
		waitpid(-1, NULL, 0);
		i++;
	}
}

void	*philo_routine(t_philo_m *m)
{
	pthread_t	thread;

	pthread_create(&thread, NULL, check_death, (void *)m);
	m->die_time = m->p->timeatstart + m->p->timetodie;
	if (m->id % 2 == 0)
		ft_usleep(timestamp() + m->p->timetoeat);
	while (ft_table(m) != 0)
		;
	pthread_join(thread, NULL);
	return (NULL);
}