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

int	main(int argc, char **argv)
{
	t_philo_p	inpparams;
	t_philo_m	philos;

	if (save_variables(argc, argv, &inpparams))
	{
		usage();
		return (0);
	}
	inpparams.timeatstart = philo_get_time();
	philo_r_init(&philos, &inpparams);
	if (inpparams.numofphilo == 1)
	{
		printf("%lld %d %s\n", (long long)0, 1, "has taken a fork");
		u_wait(inpparams.timeatstart + inpparams.timetodie);
		printf("%lld %d died\n", philo_get_time() - inpparams.timeatstart, 1);
		return (0);
	}
	philo_r_create(&philos, &inpparams);
	sem_unlink("/forks");
	sem_unlink("/pr");
	sem_unlink("/dead");
	sem_unlink("/finished");
	return (0);
}
