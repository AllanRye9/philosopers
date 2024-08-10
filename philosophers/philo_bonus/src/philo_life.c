/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oallan <oallan@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:00:24 by oallan            #+#    #+#             */
/*   Updated: 2024/08/09 13:00:28 by oallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_sleeping(t_p_mx *m)
{
	ft_printing(m, 2);
	ft_usleep(timestamp() + m->p->timetosleep);
}

void	ft_thinking(t_p_mx *m)
{
	ft_printing(m, 3);
}

void	ft_dying(t_p_mx *m)
{
	ft_usleep(m->die_time);
	ft_printing(m, 4);
}
