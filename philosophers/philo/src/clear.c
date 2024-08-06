#include "philo.h"

void free_all(t_info *data)
{
    int i;
    
    i = -1;
    while(++i < data->n_philo)
    {
        pthread_mutex_destroy(&data->philo[i].fork_l);
        pthread_mutex_destroy(data->philo[i].fork_r);
    }
    if (data->philo) {
        free(data->philo);
        data->philo = NULL;
    }
    pthread_mutex_destroy(&data->print);
    pthread_mutex_destroy(&data->m_stop);
    pthread_mutex_destroy(&data->m_eat);
    pthread_mutex_destroy(&data->dead);
}