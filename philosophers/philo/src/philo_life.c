/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oallan <oallan@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:55:30 by oallan            #+#    #+#             */
/*   Updated: 2024/08/09 12:55:33 by oallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	v_thinking(t_p_mx *m)
{
	v_print(m, 3);
}

void	v_dying(t_p_mx *m)
{
	v_pause(m->die_time);
	v_print(m, 4);
}

void	v_sleeping(t_p_mx *m)
{
	v_print(m, 2);
	v_pause(ll_timestamp() + m->p->timetosleep);
}

int	i_scheduler(t_p_mx *m)
{
	pthread_mutex_lock(m->fork_one);
	if (ll_timestamp() + m->p->timetoeat <= m->die_time
		&& (m->meals_eaten < m->p->n_meals_toeat || m->p->n_meals_toeat == -1))
		v_eating(m);
	else
	{
		pthread_mutex_unlock(m->fork_one);
		if (ll_timestamp() + m->p->timetoeat > m->die_time)
			v_dying(m);
		return (0);
	}
	if (ll_timestamp() + m->p->timetosleep > m->die_time)
	{
		m->die_time -= m->p->timetoeat;
		v_dying(m);
		return (0);
	}
	else
		v_sleeping(m);
	v_thinking(m);
	return (1);
}
