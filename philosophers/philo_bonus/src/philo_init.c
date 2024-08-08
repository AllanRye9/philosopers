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

void	init_philos(t_philo_m *philos, t_philo_p *args, int i)
{
    philos->id = i;
	philos->times_eaten = 0;
	philos->p = args;
}

int	is_finished(t_philo_m *m)
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

void	ft_printing(t_philo_m *m, enum e_print print)
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
	printf("%lld %d %s\n", timestamp() - m->p->timeatstart, m->id + 1,
		msg[(int)print]);
	sem_post(m->pr);
}

int	ft_table(t_philo_m *m)
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
