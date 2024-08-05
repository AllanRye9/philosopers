#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_args	args;

	if (init_args(&args, argc, argv) == -1)
		return (-1);
	init_semaphores(&args);
	init_monitor(&args);
	ft_philo(&args);
	kill_philos(&args);
	return (0);
}
