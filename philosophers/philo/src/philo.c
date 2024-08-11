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

void	*simulation(void *p)
{
	t_p_mx	*m;

	m = (t_p_mx *)p;
	m->die_time = m->p->start + m->p->timetodie;
	if (m->id % 2 == 0)
		v_pause(ll_timestamp() + m->p->timetoeat);
	while (1)
	{
		if (i_scheduler(m) == 0 || m->data->is_dead == 1)
			return (NULL);
	}
	return (NULL);
}

void	v_create_philos(t_p_main *p)
{
	int	i;

	i = -1;
	while (++i < p->count)
	{
		pthread_create(&p->threads[i], NULL, simulation,
			(void *)&p->philos[i]);
	}
}

void	v_join_philos(t_p_main *p)
{
	int	i;

	i = 0;
	while (i < p->count)
	{
		pthread_join(p->threads[i], NULL);
		i++;
	}
}

void	v_eating(t_p_mx *m)
{
	v_print(m, 0);
	pthread_mutex_lock(m->fork_two);
	v_print(m, 0);
	v_print(m, 1);
	m->die_time = ll_timestamp() + m->p->timetodie + m->p->timetoeat;
	v_pause(ll_timestamp() + m->p->timetoeat);
	if (m->p->n_meals_toeat != -1)
		m->meals_eaten += 1;
	pthread_mutex_unlock(m->fork_two);
	pthread_mutex_unlock(m->fork_one);
}
