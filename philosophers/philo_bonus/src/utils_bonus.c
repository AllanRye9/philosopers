/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oallan <oallan@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 21:44:40 by oallan            #+#    #+#             */
/*   Updated: 2024/08/06 21:44:41 by oallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	return (0);
}

int	ft_is_num(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!is_digit(av[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_atoi(char *str)
{
	long	num;

	if (is_num(str) == -1)
		return (-1);
	num = 0;
	while (*str)
	{
		num = num * 10 + *str - 48;
		str++;
	}
	if (num >= 0 && num <= 2147483647)
		return ((int)num);
	return (-1);
}

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, 0);
	return ((size_t)tv.tv_sec * 1000 + (size_t)tv.tv_usec / 1000);
}

void	state_printing(t_args *args, int state)
{
	sem_wait(args->stdout_s);
	if (state == TAKING_FORK)
		printf("%ld %lu has taken a fork\n", get_time() - args->start_time,
			args->philo.philo_id + 1);
	else if (state == EATING)
		printf("%ld %lu is eating\n", get_time() - args->start_time,
			args->philo.philo_id + 1);
	else if (state == SLEEPING)
		printf("%ld %lu is sleeping\n", get_time() - args->start_time,
			args->philo.philo_id + 1);
	sem_post(args->stdout_s);
}
