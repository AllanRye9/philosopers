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

#include "philo_bonus.h"

void	v_forking_process(t_p_mx *philos, t_p *a, int i)
{
	philos->id = i;
	philos->meals_eaten = 0;
	philos->p = a;
}

int	semphonize(t_p_mx *philos, t_p *a)
{
	sem_unlink("/forks");
	sem_unlink("/pr");
	sem_unlink("/dead");
	sem_unlink("/meals_eaten_s");
	sem_unlink("/finished");
	philos->forks = sem_open("/forks", O_CREAT, 0644, a->numofphilo);
	philos->meals_eaten_s = sem_open("/meals_eaten_s", O_CREAT, 0644, 1);
	philos->dead = sem_open("/dead", O_CREAT, 0644, 1);
	philos->pr = sem_open("/pr", O_CREAT, 0644, 1);
	sem_unlink("/forks");
	sem_unlink("/pr");
	sem_unlink("/dead");
	sem_unlink("/meals_eaten_s");
	return (0);
}

void	v_print(t_p_mx *m, enum ev_print print)
{
	const char	*msg[] = {
		"has taken a fork", "is eating", "is sleeping",
		"is thinking", "died"};

	if (is_finished(m))
		return ;
	sem_wait(m->dead);
	if (print == 4)
		m->finished = sem_open("/finished", O_CREAT, 0644, 9999);
	sem_post(m->dead);
	sem_wait(m->pr);
	printf("%lld %d %s\n", ll_timestamp() - m->p->start, m->id + 1,
		msg[(int)print]);
	sem_post(m->pr);
}

int	is_finished(t_p_mx *m)
{
	sem_t	*finished;

	sem_wait(m->dead);
	finished = sem_open("/finished", 0);
	if (finished == SEM_FAILED)
	{
		sem_post(m->dead);
		return (0);
	}
	sem_close(finished);
	sem_post(m->dead);
	return (1);
}

void	v_eating(t_p_mx *m)
{
	v_print(m, 0);
	{
		sem_wait(m->forks);
		v_print(m, 0);
		v_print(m, 1);
		if (ll_timestamp() + m->p->timetoeat > m->die_time)
		{
			v_dying(m);
			sem_post(m->forks);
			sem_post(m->forks);
			return ;
		}
		m->die_time = ll_timestamp() + m->p->timetodie + m->p->timetoeat;
		v_usleep(ll_timestamp() + m->p->timetoeat);
		{
			sem_wait(m->meals_eaten_s);
			if (m->p->n_meals_toeat != -1)
				m->meals_eaten += 1;
			sem_post(m->meals_eaten_s);
		}
		sem_post(m->forks);
	}
	sem_post(m->forks);
}
