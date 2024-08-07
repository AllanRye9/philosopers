/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oallan <oallan@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 21:44:33 by oallan            #+#    #+#             */
/*   Updated: 2024/08/06 21:44:34 by oallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*meals_check(void *arg)
{
	t_args	*args;
	int		i;

	args = arg;
	i = -1;
	sem_wait(args->stdout_s);
	while (++i < args->number_of_philos)
	{
		sem_post(args->stdout_s);
		sem_wait(args->ate_enough_s);
		sem_wait(args->stdout_s);
	}
	sem_post(args->stop_s);
	return (0);
}

void	ft_usleep(int ms)
{
	long	time;

	time = get_time();
	usleep(ms * 920);
	while (get_time() < time + ms)
		usleep(ms * 3);
}
