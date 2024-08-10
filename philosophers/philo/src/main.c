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
	t_p	args;
	t_p_main	p_main;

	if (var_init(ac, av, &args))
		return (display_error(), 0);
	args.start = timestamp();
	philo_init(&p_main, &args);
	if (args.numofphilo == 1)
	{
		ft_printing(p_main.philos, 0);
		ft_usleep(args.start + args.timetodie);
		printf("%lld %d died\n", timestamp() - args.start, 1);
		return (0);
	}
	philo_create(&p_main);
	philo_join(&p_main);
	free_all(&p_main);
	return (0);
}
