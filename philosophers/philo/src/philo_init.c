/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oallan <oallan@student.42abudhabi.ae>     +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 21:38:40 by oallan            #+#    #+#             */
/*   Updated: 2024/08/07 15:24:05 by oallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	init_philos(t_philo_m *philos, t_philo_p *args, int i)
{
        philos->id = i;
	      philos->times_eaten = 0;
	      philos->p = args;
	      pthread_mutex_init(&philos->left_fork, NULL);
	      pthread_mutex_init(&philos->times_eaten_m, NULL);
	      if (i + 1 == args->numofphilo)
		        philos->right_fork = &(philos - i)->left_fork;
	      else
		        philos->right_fork = &(philos + 1)->left_fork;
	      philos->first_fork = &philos->left_fork;
	      philos->secondfork = philos->right_fork;
	      if (i % 2)
	      {
		        philos->first_fork = philos->right_fork;
		        philos->secondfork = &philos->left_fork;
	      }
}
