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

void	init_philos(t_p_mx *philos, t_p *args, int i)
{
	philos->id = i;
	philos->times_eaten = 0;
	philos->p = args;
	pthread_mutex_init(&philos->left_fork, NULL);
	pthread_mutex_init(&philos->times_eaten_m, NULL);
	if (i + 1 == args->numofphilo)
		philos->right_fork = &(philos - i)->left_fork;
	else
		philos->right_fork = &(philos + 1)->left_fork;
	philos->first_fork = &philos->left_fork;
	philos->secondfork = philos->right_fork;
	if (i % 2)
	{
		philos->first_fork = philos->right_fork;
		philos->secondfork = &philos->left_fork;
	}
}

void	ft_printing(t_p_mx *m, enum e_print print)
{
	const char	*msg[] = {
		"has taken a fork", "is eating", "is sleeping",
		"is thinking", "died"};

	pthread_mutex_lock(m->pr);
	if (m->data->is_dead != true && print == 4)
	{
		printf("%lld %d %s\n", timestamp() - m->p->start, m->id + 1,
			msg[(int)print]);
		m->data->is_dead = true;
		pthread_mutex_unlock(m->pr);
		return ;
	}
	else if (m->data->is_dead == true)
	{
		pthread_mutex_unlock(m->pr);
		return ;
	}
	else
	{
		printf("%lld %d %s\n", timestamp() - m->p->start, m->id + 1,
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
		ft_usleep(timestamp() + m->p->timetoeat);
	while (1)
	{
		if (ft_table(m) == 0 || m->data->is_dead == 1)
			return (NULL);
	}
	return (NULL);
}
