#include "philo.h"

long long timestamp(void)
{
    struct timeval  t;
    
    gettimeofday(&t, NULL);
    return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

void    ft_usleep(int ms)
{
    long int time;
    
    time = timestamp();
    while(timestamp() - time < ms)
        usleep(ms / 10);
}