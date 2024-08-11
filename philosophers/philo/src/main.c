/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oallan <oallan@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 21:38:45 by oallan            #+#    #+#             */
/*   Updated: 2024/08/07 15:25:25 by oallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_p			a;
	t_p_main	p_main;

	if (i_init_args(ac, av, &a))
		return (v_error(), 0);
	a.start = ll_timestamp();
	i_philo_alloc(&p_main, &a);
	if (a.numofphilo == 1)
	{
		v_print(p_main.philos, 0);
		v_pause(a.start + a.timetodie);
		printf("%lld %d died\n", ll_timestamp() - a.start, 1);
		return (0);
	}
	v_create_philos(&p_main);
	v_join_philos(&p_main);
	v_free_all(&p_main);
	return (0);
}
