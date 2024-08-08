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

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo_p 	args;
	t_philo_run	run;

	if (var_init(ac, av, &args))
		return (display_error(), 0);
	args.timestart = timestamp();
	philo_init(&run, &args);
	if(args.numofphilo == 1)
	{
		ft_printing(philo_r.philos, 0);
		ft_usleep(args.timeatstart + args.timetodie);
		printf("%lld %d died\n", philo_get_time() - args.timeatstart, 1);
		return (0);
	}
	return (0);
}
