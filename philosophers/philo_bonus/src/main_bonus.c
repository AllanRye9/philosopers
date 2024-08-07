/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oallan <oallan@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 21:44:30 by oallan            #+#    #+#             */
/*   Updated: 2024/08/06 21:44:31 by oallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_args	args;

	if (ft_is_num(argv))
	{
		printf("Invalid Input\n");
		exit(1);
	}
	if (init_args(&args, argc, argv) == -1)
		return (kill_philos(&args), -1);
	init_semaphores(&args);
	init_monitor(&args);
	ft_philo(&args);
	kill_philos(&args);
	return (0);
}
