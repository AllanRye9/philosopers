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

#include "philo_bonus.h"

int	var_init(int ac, char **av, t_philo_p *args)
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

int	philo_init(t_philo_m *philos, t_philo_p *args)
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
