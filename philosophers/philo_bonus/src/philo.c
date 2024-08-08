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

void	*check_death(void *m)
{
	t_philo_m	*philos;

	philos = (t_philo_m *)m;
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
			sem_wait(philos->times_eaten_s);
			if (philos->times_eaten == philos->p->numtoeat)
			{
				sem_post(philos->times_eaten_s);
				return (NULL);
			}
			sem_post(philos->times_eaten_s);
		}
	}
}

void	philo_create(t_philo_m *philos, t_philo_p *args)
{
	int			i;
	pid_t		id;

	i = 0;
	while (i < args->numofphilo)
	{
		id = fork();
		if (id == 0)
		{
			init_philos(philos, args, i);
			philo_routine(philos);
			return ;
		}
		if (id != -1)
			i++;
	}
	if (id != 0)
		philo_r_wait(args);
	sem_close(philos->dead);
	sem_close(philos->pr);
	sem_close(philos->forks);
	sem_close(philos->finished);
}


void	ft_eating(t_philo_m *m)
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
