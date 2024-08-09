/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oallan <oallan@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 21:38:45 by oallan            #+#    #+#             */
/*   Updated: 2024/08/07 15:25:25 by oallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_philo_p	args;
	t_philo_m	philos;

	if (save_variables(ac, av, &args))
	{
		usage();
		return (0);
	}
	args.timeatstart = philo_get_time();
	philo_r_init(&philos, &args);
	if (args.numofphilo == 1)
	{
		printf("%lld %d %s\n", (long long)0, 1, "has taken a fork");
		u_wait(args.timeatstart + args.timetodie);
		printf("%lld %d died\n", philo_get_time() - args.timeatstart, 1);
		return (0);
	}
	philo_r_create(&philos, &args);
	sem_unlink("/forks");
	sem_unlink("/pr");
	sem_unlink("/dead");
	sem_unlink("/finished");
	return (0);
}
