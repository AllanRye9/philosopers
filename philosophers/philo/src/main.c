#include "philo.h"

int main(int ac, char **av)
{
    t_info data;

    if (ac != 5 && ac != 6)
        return (0);
    if(var_init(&data, av) == 1)
        return(free(data.philo), 0);
    philo_init(&data);
    free_all(&data);
    return (0);
}