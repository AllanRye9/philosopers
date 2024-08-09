/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oallan <oallan@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 21:38:59 by oallan            #+#    #+#             */
/*   Updated: 2024/08/07 15:52:50 by oallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_msec	philo_get_time(void)
{
	struct timeval	t;

	if (gettimeofday(&t, NULL))
		return (-1);
	return (((long long)t.tv_sec * 1000) + ((long long)t.tv_usec / 1000));
}

void	u_wait(t_msec waiting_time)
{
	t_msec	t;

	t = philo_get_time();
	while (waiting_time - t > 5)
	{
		usleep(1000 * (waiting_time - t - 5));
		t = philo_get_time();
	}
	while (waiting_time > t)
		t = philo_get_time();
}