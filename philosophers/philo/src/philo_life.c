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

void	ft_thinking(t_p_mx *m)
{
	ft_printing(m, 3);
}

void	ft_dying(t_p_mx *m)
{
	ft_usleep(m->die_time);
	ft_printing(m, 4);
}

void	ft_sleeping(t_p_mx *m)
{
	ft_printing(m, 2);
	ft_usleep(timestamp() + m->p->timetosleep);
}

int	ft_table(t_p_mx *m)
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
