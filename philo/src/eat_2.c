/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:18:33 by ssteveli          #+#    #+#             */
/*   Updated: 2024/04/01 14:18:33 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void drop_right_fork(t_philo *philo)
{
    pthread_mutex_unlock(philo->right_fork);
}

int take_left_fork(t_philo *philo)
{
    if (philo_died(philo) || get_philo_state(philo) == DEAD)
        return (1);
     pthread_mutex_lock(philo->left_fork);
    print_msg(philo->data, philo->id, "has taken a fork");
    return (0);
}

int take_right_fork(t_philo *philo)
{
    if (philo_died(philo) || get_philo_state(philo) == DEAD)
        return (1);
     pthread_mutex_lock(philo->right_fork);
    print_msg(philo->data, philo->id, "has taken a fork");
    return (0);
}

int take_forks(t_philo *philo)
{
    if (get_number_philos(philo->data) == 1)
        return (ft_1_philo(philo));
    if (take_right_fork(philo) != 0)
        return (1);
    if (take_left_fork(philo) != 0)
    {
        drop_right_fork(philo);
        return (1);
    }
    return (0);
}