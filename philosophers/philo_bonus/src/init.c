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

int	save_variables(int argc, char **argv, t_philo_p *inpparams)
{
	inpparams->numtoeat = -1;
	if (argc != 6 && argc != 5)
		return (1);
	if (my_atoi(argv[1], &inpparams->numofphilo))
		return (1);
	if (my_atoll(argv[2], &inpparams->timetodie))
		return (1);
	if (my_atoll(argv[3], &inpparams->timetoeat))
		return (1);
	if (my_atoll(argv[4], &inpparams->timetosleep))
		return (1);
	if (argc == 6)
	{
		if (my_atoi(argv[5], &inpparams->numtoeat))
			return (1);
	}
	if (inpparams->numofphilo == 0 || inpparams->numtoeat == 0)
		return (1);
	return (0);
}
