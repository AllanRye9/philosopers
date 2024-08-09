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

int	save_variables(int ac, char **av, t_philo_p *args)
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
