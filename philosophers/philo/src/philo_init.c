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

void	ft_printing(t_philo_m *m, enum e_print print)
{
	const char	*msg[] = {
		"has taken a fork", "is eating", "is sleeping",
		"is thinking", "died"};

	pthread_mutex_lock(m->pr);
	if (m->data->is_dead != true && print == 4)
	{
		printf("%lld %d %s\n", philo_get_time() - m->p->timeatstart, m->id + 1,
			msg[(int)print]);
		m->data->is_dead = true;
		pthread_mutex_unlock(m->pr);
		return ;
	}
	else if (m->data->is_dead == true)
	{
		pthread_mutex_unlock(m->pr);
		return ;
	}
	else
	{
		printf("%lld %d %s\n", philo_get_time() - m->p->timeatstart, m->id + 1,
			msg[(int)print]);
		pthread_mutex_unlock(m->pr);
	}
}
