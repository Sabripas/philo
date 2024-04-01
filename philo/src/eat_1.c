/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:58:34 by ssteveli          #+#    #+#             */
/*   Updated: 2024/04/01 13:58:34 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void drop_forks(t_philo *philo)
{
    pthread_mutex_unlock(philo->left_fork);
    pthread_mutex_unlock(philo->right_fork);
}

void update_last_time_eat(t_philo *philo)
{
    pthread_mutex_lock(&philo->mut_last_time_eat);
    philo->last_time_eat = get_time();
    pthread_mutex_unlock(&philo->mut_last_time_eat);
}

void update_nb_meals_had(t_philo *philo)
{
    pthread_mutex_lock(&philo->mut_number_meals_eat);
    philo->number_meals_eat++;
    pthread_mutex_unlock(&philo->mut_number_meals_eat);
}

void sleep_for_eating(t_philo *philo)
{
    ft_usleep(get_eat_time(philo->data));
}

int eat(t_philo *philo)
{
    if (take_forks(philo) != 0)
        return (1);
    set_philo_state(philo, EATING);
    print_msg(philo->data, philo->id, "is eating");
    update_last_time_eat(philo);
    sleep_for_eating(philo);
    update_nb_meals_had(philo);
    drop_forks(philo);
    return (0);
}
