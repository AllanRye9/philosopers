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

int	ft_table(t_p_mx *m)
{
	if (is_finished(m))
		return (0);
	sem_wait(m->forks);
	if (timestamp() <= m->die_time
		&& (m->times_eaten < m->p->numtoeat || m->p->numtoeat == -1))
		ft_eating(m);
	else
	{
		sem_post(m->forks);
		if (timestamp() + m->p->timetoeat > m->die_time)
			ft_dying(m);
		return (0);
	}
	if (is_finished(m))
		return (0);
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

void	*schedule(t_p_mx *m)
{
	pthread_t	thread;

	pthread_create(&thread, NULL, check_death, (void *)m);
	m->die_time = m->p->start + m->p->timetodie;
	if (m->id % 2 == 0)
		ft_usleep(timestamp() + m->p->timetoeat);
	while (ft_table(m) != 0)
		;
	pthread_join(thread, NULL);
	return (NULL);
}

void	create_philo(t_p_mx *philos, t_p *args)
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
			schedule(philos);
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

void	philo_r_wait(t_p *args)
{
	int	i;

	i = 0;
	while (i < args->numofphilo)
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
