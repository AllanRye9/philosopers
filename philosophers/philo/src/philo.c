/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oallan <oallan@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 21:38:49 by oallan            #+#    #+#             */
/*   Updated: 2024/08/07 15:56:46 by oallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *philo)
{
	t_philo_m	*m;

	m = (t_philo_m *)philo;
	m->die_time = m->p->timeatstart + m->p->timetodie;
	if (m->id % 2 == 0)
		ft_usleep(timestamp() + m->p->timetoeat);
	while (1)
	{
		if (ft_table(m) == 0 || m->data->is_dead == 1)
			return (NULL);
	}
	return (NULL);
}

void	philo_create(t_philo_run *philo_r)
{
	int	i;

	i = 0;
	while (i < philo_r->count)
	{
		pthread_create(&philo_r->threads[i], NULL, philo_routine,
			(void *)&philo_r->philos[i]);
		i++;
	}
}

void	philo_join(t_philo_run *philo_r)
{
	int	i;

	i = 0;
	while (i < philo_r->count)
	{
		pthread_join(philo_r->threads[i], NULL);
		i++;
	}
}

void	ft_eating(t_philo_m *m)
{
	ft_printing(m, 0);
	pthread_mutex_lock(m->secondfork);
	ft_printing(m, 0);
	ft_printing(m, 1);
	m->die_time = timestamp() + m->p->timetodie + m->p->timetoeat;
	ft_usleep(timestamp() + m->p->timetoeat);
	if (m->p->numtoeat != -1)
		m->times_eaten += 1;
	pthread_mutex_unlock(m->secondfork);
	pthread_mutex_unlock(m->first_fork);
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

int	ft_table(t_philo_m *m)
{
	pthread_mutex_lock(m->first_fork);
	if (timestamp() + m->p->timetoeat <= m->die_time
		&& (m->times_eaten < m->p->numtoeat || m->p->numtoeat == -1))
		ft_eating(m);
	else
	{
		pthread_mutex_unlock(m->first_fork);
		if (timestamp() + m->p->timetoeat > m->die_time)
			ft_dying(m);
		return (0);
	}
	if (timestamp() + m->p->timetosleep > m->die_time)
	{
		m->die_time -= m->p->timetoeat;
		ft_dying(m);
		return (0);
	}
	else
		ft_sleeping(m);
	ft_thinking(m);
	return (1);
}

void	*philo_life(void *p)
{
	t_philo_m	*m;

	m = (t_philo_m *)p;
	m->die_time = m->p->timeatstart + m->p->timetodie;
	if (m->id % 2 == 0)
		ft_usleep(timestamp() + m->p->timetoeat);
	while (1)
	{
		if (ft_table(m) == 0 || m->data->is_dead == 1)
			return (NULL);
	}
	return (NULL);
}
