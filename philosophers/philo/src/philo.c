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

void	*schedule(void *philo)
{
	t_p_mx	*m;

	m = (t_p_mx *)philo;
	m->die_time = m->p->start + m->p->timetodie;
	if (m->id % 2 == 0)
		ft_usleep(timestamp() + m->p->timetoeat);
	while (1)
	{
		if (ft_table(m) == 0 || m->data->is_dead == 1)
			return (NULL);
	}
	return (NULL);
}

void	philo_create(t_p_main *philo_r)
{
	int	i;

	i = 0;
	while (i < philo_r->count)
	{
		pthread_create(&philo_r->threads[i], NULL, schedule,
			(void *)&philo_r->philos[i]);
		i++;
	}
}

void	philo_join(t_p_main *philo_r)
{
	int	i;

	i = 0;
	while (i < philo_r->count)
	{
		pthread_join(philo_r->threads[i], NULL);
		i++;
	}
}

void	ft_eating(t_p_mx *m)
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
