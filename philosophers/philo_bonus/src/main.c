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
	t_p	args;
	t_p_mx	philos;

	if (initialization(ac, av, &args))
	{
		usage();
		return (0);
	}
	args.start = timestamp();
	semphonize(&philos, &args);
	if (args.numofphilo == 1)
	{
		printf("%lld %d %s\n", (long long)0, 1, "has taken a fork");
		ft_usleep(args.start + args.timetodie);
		printf("%lld %d died\n", timestamp() - args.start, 1);
		return (0);
	}
	create_philo(&philos, &args);
	sem_unlink("/forks");
	sem_unlink("/pr");
	sem_unlink("/dead");
	sem_unlink("/finished");
	return (0);
}
