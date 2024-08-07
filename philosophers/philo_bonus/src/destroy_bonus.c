/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oallan <oallan@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 21:44:18 by oallan            #+#    #+#             */
/*   Updated: 2024/08/06 21:44:19 by oallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	*death_check(void *arg)
{
	t_args	*args;
	long	current_time;

	args = arg;
	while (1)
	{
		current_time = get_time();
		if (current_time - args->philo.time_of_last_meal > args->time_to_die)
		{
			sem_wait(args->stdout_s);
			printf("%ld %lu died\n", get_time() - args->start_time,
				args->philo.philo_id + 1);
			sem_post(args->stop_s);
			exit(0);
		}
	}
	return (0);
}

void	kill_philos(t_args *args)
{
	int	i;

	i = 0;
	while (i < args->number_of_philos)
	{
		kill(args->philo_pid[i], SIGKILL);
		i++;
	}
	free(&args->monitor_tid);
	if (args->philo_pid != NULL)
		free(args->philo_pid);
	sem_close(args->ate_enough_s);
	sem_close(args->fork_s);
	sem_close(args->stop_s);
	sem_close(args->stdout_s);
}
