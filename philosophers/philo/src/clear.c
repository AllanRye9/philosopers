/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oallan <oallan@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 21:38:30 by oallan            #+#    #+#             */
/*   Updated: 2024/08/07 15:49:20 by oallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	display_error(void)
{
	printf("Invalid Argument or Format\n");
}

void	free_all(t_p_main *philo_r)
{
	int	i;

	i = -1;
	while (++i < philo_r->count)
	{
		pthread_mutex_destroy(&philo_r->philos[i].times_eaten_m);
		pthread_mutex_destroy(&philo_r->philos[i].left_fork);
	}
	pthread_mutex_destroy(&philo_r->printing);
	free(philo_r->philos);
	free(philo_r->threads);
}
