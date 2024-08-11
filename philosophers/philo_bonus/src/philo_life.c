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

void	v_sleeping(t_p_mx *m)
{
	v_print(m, 2);
	v_usleep(ll_timestamp() + m->p->timetosleep);
}

void	v_thinking(t_p_mx *m)
{
	v_print(m, 3);
}

void	v_dying(t_p_mx *m)
{
	v_usleep(m->die_time);
	v_print(m, 4);
}
