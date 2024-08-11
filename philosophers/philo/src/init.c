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

#include "philo.h"

int	i_init_args(int ac, char **av, t_p *a)
{
	a->n_meals_toeat = -1;
	if (ac != 6 && ac != 5)
		return (1);
	if (i_atoi(av[1], &a->numofphilo))
		return (1);
	if (i_atoll(av[2], &a->timetodie))
		return (1);
	if (i_atoll(av[3], &a->timetoeat))
		return (1);
	if (i_atoll(av[4], &a->timetosleep))
		return (1);
	if (ac == 6)
	{
		if (i_atoi(av[5], &a->n_meals_toeat))
			return (1);
	}
	if (a->numofphilo == 0 || a->n_meals_toeat == 0)
		return (1);
	return (0);
}

int	i_philo_alloc(t_p_main *p, t_p *a)
{
	int	i;

	p->philos = malloc(sizeof(t_p_mx) * a->numofphilo);
	p->threads = malloc(sizeof(pthread_t) * a->numofphilo);
	p->count = a->numofphilo;
	p->is_dead = 0;
	pthread_mutex_init(&p->printing, NULL);
	if (!p->philos || !p->threads)
	{
		v_free_all(p);
		return (1);
	}
	i = -1;
	while (++i < a->numofphilo)
	{
		p->philos[i].pr = &p->printing;
		p->philos[i].data = p;
		v_forking(&p->philos[i], a, i);
	}
	return (0);
}
