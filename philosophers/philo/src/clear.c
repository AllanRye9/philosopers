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

void	v_error(void)
{
	printf("Invalid Argument or Format\n");
}

void	v_free_all(t_p_main *p)
{
	int	i;

	i = -1;
	while (++i < p->count)
	{
		pthread_mutex_destroy(&p->philos[i].meals_eaten_m);
		pthread_mutex_destroy(&p->philos[i].left_fork);
	}
	pthread_mutex_destroy(&p->printing);
	free(p->philos);
	free(p->threads);
}
