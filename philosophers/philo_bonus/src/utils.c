/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oallan <oallan@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 21:39:02 by oallan            #+#    #+#             */
/*   Updated: 2024/08/07 15:51:33 by oallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	check_int(int sign, int *n)
{
	if (!sign && *n == INT_MIN)
		return (2);
	if (*n < 0 && *n != INT_MIN)
		return (2);
	return (0);
}

int	my_atoi(const char *str, int *n)
{
	int	sign;

	sign = 0;
	*n = 0;
	if (*str == '-')
		sign = 1;
	if (*str == '-' || *str == '+')
		str++;
	if (*str < '0' && *str > '9')
		return (-1);
	while (*str >= '0' && *str <= '9')
	{
		*n *= 10;
		*n += *str - '0';
		if (check_int(sign, n))
			return (2);
		str++;
	}
	if (sign)
		*n *= -1;
	if (*str == '\0')
		return (0);
	return (1);
}

int	check_ll(int sign, t_msec *n)
{
	if (!sign && *n == LLONG_MIN)
		return (2);
	if (*n < 0 && *n != LLONG_MIN)
		return (2);
	return (0);
}

int	my_atoll(const char *str, t_msec *n)
{
	int	sign;

	sign = 0;
	*n = 0;
	if (*str == '+')
		str++;
	if (*str < '0' && *str > '9')
		return (-1);
	while (*str >= '0' && *str <= '9')
	{
		*n *= 10;
		*n += *str - '0';
		if (check_ll(sign, n))
			return (2);
		str++;
	}
	if (*str == '\0')
		return (0);
	return (1);
}