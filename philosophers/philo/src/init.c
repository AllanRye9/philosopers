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

int	var_init(int ac, char **av, t_p *args)
{
	args->numtoeat = -1;
	if (ac != 6 && ac != 5)
		return (1);
	if (my_atoi(av[1], &args->numofphilo))
		return (1);
	if (my_atoll(av[2], &args->timetodie))
		return (1);
	if (my_atoll(av[3], &args->timetoeat))
		return (1);
	if (my_atoll(av[4], &args->timetosleep))
		return (1);
	if (ac == 6)
	{
		if (my_atoi(av[5], &args->numtoeat))
			return (1);
	}
	if (args->numofphilo == 0 || args->numtoeat == 0)
		return (1);
	return (0);
}

int	philo_init(t_p_main *philo_r, t_p *args)
{
	int	i;

	philo_r->philos = malloc(sizeof(t_p_mx) * args->numofphilo);
	philo_r->threads = malloc(sizeof(pthread_t) * args->numofphilo);
	philo_r->count = args->numofphilo;
	philo_r->is_dead = 0;
	pthread_mutex_init(&philo_r->printing, NULL);
	if (!philo_r->philos || !philo_r->threads)
	{
		free_all(philo_r);
		return (1);
	}
	i = 0;
	while (i < args->numofphilo)
	{
		philo_r->philos[i].pr = &philo_r->printing;
		philo_r->philos[i].data = philo_r;
		init_philos(&philo_r->philos[i], args, i);
		i++;
	}
	return (0);
}
