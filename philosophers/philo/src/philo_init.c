/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oallan <oallan@student.42abudhabi.ae>     +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 21:38:40 by oallan            #+#    #+#             */
/*   Updated: 2024/08/07 15:24:05 by oallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	v_forking(t_p_mx *philos, t_p *a, int i)
{
	philos->id = i;
	philos->meals_eaten = 0;
	philos->p = a;
	pthread_mutex_init(&philos->left_fork, NULL);
	pthread_mutex_init(&philos->meals_eaten_m, NULL);
	if (i + 1 == a->numofphilo)
		philos->right_fork = &(philos - i)->left_fork;
	else
		philos->right_fork = &(philos + 1)->left_fork;
	philos->fork_one = &philos->left_fork;
	philos->fork_two = philos->right_fork;
	if (i % 2)
	{
		philos->fork_one = philos->right_fork;
		philos->fork_two = &philos->left_fork;
	}
}

void	v_print(t_p_mx *m, enum ev_print print)
{
	const char	*msg[] = {
		"has taken a fork", "is eating", "is sleeping",
		"is thinking", "died"};

	pthread_mutex_lock(m->pr);
	if (m->data->is_dead != 1 && print == 4)
	{
		printf("%lld %d %s\n", ll_timestamp() - m->p->start, m->id + 1,
			msg[(int)print]);
		m->data->is_dead = 1;
		pthread_mutex_unlock(m->pr);
		return ;
	}
	else if (m->data->is_dead == 1)
	{
		pthread_mutex_unlock(m->pr);
		return ;
	}
	else
	{
		printf("%lld %d %s\n", ll_timestamp() - m->p->start, m->id + 1,
			msg[(int)print]);
		pthread_mutex_unlock(m->pr);
	}
}

void	*philo_life(void *p)
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
