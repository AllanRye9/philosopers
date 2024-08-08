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

#include "philo.h"

void	philo_create(t_philo_run *philo_r)
{
	int	i;

	i = 0;
	while (i < philo_r->count)
	{
		pthread_create(&philo_r->threads[i], NULL, philo_routine,
			(void *)&philo_r->philos[i]);
		i++;
	}
}

void	philo_join(t_philo_run *philo_r)
{
	int	i;

	i = 0;
	while (i < philo_r->count)
	{
		pthread_join(philo_r->threads[i], NULL);
		i++;
	}
}

void	*check_death(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	ft_usleep(philo->info->t_die + 1);
	pthread_mutex_lock(&philo->info->m_eat);
	pthread_mutex_lock(&philo->info->m_stop);
	if (!is_dead(philo, 0) && timestamp() - \
		philo->last_ate >= (long)(philo->info->t_die))
	{
		pthread_mutex_unlock(&philo->info->m_eat);
		pthread_mutex_unlock(&philo->info->m_stop);
		print(philo, " died\n");
		is_dead(philo, 1);
	}
	pthread_mutex_unlock(&philo->info->m_eat);
	pthread_mutex_unlock(&philo->info->m_stop);
	return (NULL);
}

int	is_dead(t_philo *philo, int np)
{
	pthread_mutex_lock(&philo->info->dead);
	if (np)
		philo->info->stop = 1;
	if (philo->info->stop)
	{
		pthread_mutex_unlock(&philo->info->dead);
		return (1);
	}
	pthread_mutex_unlock(&philo->info->dead);
	return (0);
}

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->fork_l));
	print(philo, " has taken a fork\n");
	if (philo->info->n_philo == 1)
	{
		ft_usleep(philo->info->t_die * 2);
		return ;
	}
	pthread_mutex_lock((philo->fork_r));
	print(philo, " has taken a fork\n");
}

void	philo_eat(t_philo *philo)
{
	print(philo, " is eating\n");
	pthread_mutex_lock(&(philo->info->m_eat));
	philo->last_ate = timestamp();
	philo->m_count++;
	pthread_mutex_unlock(&(philo->info->m_eat));
	ft_usleep(philo->info->t_eat);
	pthread_mutex_unlock((philo->fork_r));
	pthread_mutex_unlock(&(philo->fork_l));
	print(philo, " is sleeping\n");
	ft_usleep(philo->info->t_sleep);
	print(philo, " is thinking\n");
}

void	*philo_life(void *p)
{
	t_philo		*philo;
	pthread_t	t;

	philo = (t_philo *)p;
	if (philo->n % 2 == 0)
		ft_usleep(philo->info->t_eat / 10);
	while (!is_dead(philo, 0))
	{
		pthread_create(&t, NULL, check_death, p);
		take_fork(philo);
		philo_eat(philo);
		pthread_detach(t);
		if (philo->m_count == philo->info->nx_eat)
		{
			pthread_mutex_lock(&philo->info->m_stop);
			if (++philo->info->p_eat == philo->info->n_philo)
			{
				pthread_mutex_unlock(&philo->info->m_stop);
				is_dead(philo, 2);
			}
			pthread_mutex_unlock(&philo->info->m_stop);
			return (NULL);
		}
	}
	return (NULL);
}
