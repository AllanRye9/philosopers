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
#include "philo_bonus.h"

int	i_scheduler(t_p_mx *m)
{
	if (is_finished(m))
		return (0);
	sem_wait(m->forks);
	if (ll_timestamp() <= m->die_time
		&& (m->meals_eaten < m->p->n_meals_toeat || m->p->n_meals_toeat == -1))
		v_eating(m);
	else
	{
		sem_post(m->forks);
		if (ll_timestamp() + m->p->timetoeat > m->die_time)
			v_dying(m);
		return (0);
	}
	if (is_finished(m))
		return (0);
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

void	*simulation(t_p_mx *m)
{
	pthread_t	thread;

	pthread_create(&thread, NULL, check_death, (void *)m);
	m->die_time = m->p->start + m->p->timetodie;
	if (m->id % 2 == 0)
		v_usleep(ll_timestamp() + m->p->timetoeat);
	while (i_scheduler(m) != 0)
		continue;
	pthread_join(thread, NULL);
	return (NULL);
}

void	create_philo_process(t_p_mx *philos, t_p *a)
{
	int			i;
	pid_t		id;

	i = 0;
	while (i < a->numofphilo)
	{
		id = fork();
		if (id == 0)
		{
			v_forking_process(philos, a, i);
			simulation(philos);
			return ;
		}
		if (id != -1)
			i++;
	}
	if (id != 0)
		v_end_child(a);
	sem_close(philos->dead);
	sem_close(philos->pr);
	sem_close(philos->forks);
	sem_close(philos->finished);
}

void	v_end_child(t_p *a)
{
	int	i;

	i = 0;
	while (i < a->numofphilo)
	{
		waitpid(-1, NULL, 0);
		i++;
	}
}

void	*check_death(void *m)
{
	t_p_mx	*philos;

	philos = (t_p_mx *)m;
	while (1)
	{
		if (is_finished(m))
		{
			sem_unlink("/finished");
			kill(0, SIGKILL);
			return (NULL);
		}
		else
		{
			sem_wait(philos->meals_eaten_s);
			if (philos->meals_eaten == philos->p->n_meals_toeat)
			{
				sem_post(philos->meals_eaten_s);
				return (NULL);
			}
			sem_post(philos->meals_eaten_s);
		}
	}
}
