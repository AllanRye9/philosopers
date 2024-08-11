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
	t_p	a;
	t_p_mx	philos;

	if (initialization(ac, av, &a))
		return (v_error_msg(), 0);
	a.start = ll_timestamp();
	semphonize(&philos, &a);
	if (a.numofphilo == 1)
	{
		printf("%lld %d %s\n", (long long)0, 1, "has taken a fork");
		v_usleep(a.start + a.timetodie);
		printf("%lld %d died\n", ll_timestamp() - a.start, 1);
		return (0);
	}
	create_philo_process(&philos, &a);
	sem_unlink("/forks");
	sem_unlink("/pr");
	sem_unlink("/dead");
	sem_unlink("/finished");
	return (0);
}
