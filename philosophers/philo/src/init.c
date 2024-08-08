/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oallan <oallan@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 21:38:40 by oallan            #+#    #+#             */
/*   Updated: 2024/08/07 15:24:05 by oallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	var_init(int ac, char **av, t_philo *args)
{
	args->numtoeat = -1;
	if (ac != 6 && ac != 5)
		return (1);
	if (my_atoi(av[1], &args->numofphilo))
		return (1);
	if (my_atoll(argv[2], &args->timetodie))
		return (1);
	if (my_atoll(argv[3], &args->timetoeat))
		return (1);
	if (my_atoll(argv[4], &args->timetosleep))
		return (1);
	if (ac == 6)
	{
		if (my_atoi(argv[5], &args->numtoeat))
			return (1);
	}
	if (args->numofphilo == 0 || args->numtoeat == 0)
		return (1);
	return (0);
}

int	philo_init(t_info *data)
{
	int	i;

	data->t_start = timestamp();
	i = -1;
	while (++i < data->n_philo)
	{
		data->philo[i].n = i + 1;
		data->philo[i].last_ate = 0;
		data->philo[i].fork_r = NULL;
		data->philo[i].info = data;
		data->philo[i].m_count = 0;
		pthread_mutex_init(&(data->philo[i].fork_l), NULL);
		if (i == data->n_philo - 1)
			data->philo[i].fork_r = &data->philo[0].fork_l;
		else
			data->philo[i].fork_r = &data->philo[i + 1].fork_l;
		if (pthread_create(&data->philo[i].thread, NULL, \
			&philo_life, &(data->philo[i])) != 0)
			return (-1);
	}
	i = -1;
	while (++i < data->n_philo)
		if (pthread_join(data->philo[i].thread, NULL) != 0)
			return (-1);
	return (0);
}
