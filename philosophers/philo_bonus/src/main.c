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
	t_philo_p 	args;
	t_philo_m	philo_run;

	if (var_init(ac, av, &args))
		return (display_error(), 0);
	args.timeatstart = timestamp();
	philo_init(&philo_run, &args);
	if(args.numofphilo == 1)
	{
		printf("%lld %d %s\n", (long long)0, 1, "has taken a fork");
		ft_usleep(args.timeatstart + args.timetodie);
		printf("%lld %d died\n", timestamp() - args.timeatstart, 1);
		return (0);
	}
	philo_create(&philo_run, &args);
	sem_unlink("/forks");
	sem_unlink("/pr");
	sem_unlink("/dead");
	sem_unlink("/finished");
	return (0);
}
