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

#include "philo.h"

t_msec	ll_timestamp(void)
{
	struct timeval	t;

	if (gettimeofday(&t, NULL))
		return (-1);
	return (((long long)t.tv_sec * 1000) + ((long long)t.tv_usec / 1000));
}

void	v_pause(t_msec ms)
{
	t_msec	t;

	t = ll_timestamp();
	while (ms - t > 5)
	{
		usleep(1000 * (ms - t - 5));
		t = ll_timestamp();
	}
	while (ms > t)
		t = ll_timestamp();
}
