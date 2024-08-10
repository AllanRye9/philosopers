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

void	init_philos(t_p_mx *philos, t_p *args, int i)
{
	philos->id = i;
	philos->times_eaten = 0;
	philos->p = args;
}

int	semphonize(t_p_mx *philos, t_p *args)
{
	sem_unlink("/forks");
	sem_unlink("/pr");
	sem_unlink("/dead");
	sem_unlink("/times_eaten_s");
	sem_unlink("/finished");
	philos->forks = sem_open("/forks", O_CREAT, 0644, args->numofphilo);
	philos->times_eaten_s = sem_open("/times_eaten_s", O_CREAT, 0644, 1);
	philos->dead = sem_open("/dead", O_CREAT, 0644, 1);
	philos->pr = sem_open("/pr", O_CREAT, 0644, 1);
	sem_unlink("/forks");
	sem_unlink("/pr");
	sem_unlink("/dead");
	sem_unlink("/times_eaten_s");
	return (0);
}

void	ft_printing(t_p_mx *m, enum e_print print)
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
	printf("%lld %d %s\n", timestamp() - m->p->start, m->id + 1,
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

void	ft_eating(t_p_mx *m)
{
	ft_printing(m, 0);
	{
		sem_wait(m->forks);
		ft_printing(m, 0);
		ft_printing(m, 1);
		if (timestamp() + m->p->timetoeat > m->die_time)
		{
			ft_dying(m);
			sem_post(m->forks);
			sem_post(m->forks);
			return ;
		}
		m->die_time = timestamp() + m->p->timetodie + m->p->timetoeat;
		ft_usleep(timestamp() + m->p->timetoeat);
		{
			sem_wait(m->times_eaten_s);
			if (m->p->numtoeat != -1)
				m->times_eaten += 1;
			sem_post(m->times_eaten_s);
		}
		sem_post(m->forks);
	}
	sem_post(m->forks);
}
