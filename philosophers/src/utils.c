#include "philo.h"

int ft_atoi(char *s)
{
    int i;
    int res;
    int sign;
    
    sign = 1;
    res = 0;
    i = 0;
    while(s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
        i++;
    if(s[i] == '-')
    {
        sign = -1;
        i++;
    }
    if (s[i] == '-' || s[i] == '+')
        i++;
    while(s[i] >= '0' && s[i] <= '9')
    {
        res = res * 10 + s[i] - '0';
        i++;
    }
    return (res * sign);
}

int is_digit(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int is_num(char **av)
{
    int i;
    int j;

    i = 1;
    while(av[i])
    {
        j = 0;
        while(av[i][j])
        {
            if(!is_digit(av[i][j]))
                return (1);
            j++;
        }
    i++;
    }
    return (0);
}

void print(t_philo *philo, char *s)
{
    long int time;
    
    pthread_mutex_lock(&(philo->info->print));
    time = timestamp() - philo->info->t_start;
    if(!philo->info->stop && time >= 0  && time <= INT_MAX &&\
        !is_dead(philo, 0))
        printf("%lld %d %s", timestamp() - philo->info->t_start, \
                philo->n, s);
    pthread_mutex_unlock(&(philo->info->print));
}