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

#include "philo_bonus.h"

void	usage(void)
{
	printf("Invalid Argument\nUsage: program_name number_of_philosophers "
		"time_to_die time_to_eat time_to_sleep"
		" [number_of_times_each_philosopher_must_eat]\n");
}
