/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:26:13 by ssteveli          #+#    #+#             */
/*   Updated: 2024/04/01 14:26:13 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

uint64_t	get_die_time(t_data *data)
{
	uint64_t	die_time;

	pthread_mutex_lock(&data->mut_die_time);
	die_time = data->die_time;
	pthread_mutex_unlock(&data->mut_die_time);
	return (die_time);
}

uint64_t	get_sleep_time(t_data *data)
{
	uint64_t	sleep_time;

	pthread_mutex_lock(&data->mut_sleep_time);
	sleep_time = data->sleep_time;
	pthread_mutex_unlock(&data->mut_sleep_time);
	return (sleep_time);
}

uint64_t	get_eat_time(t_data *data)
{
	uint64_t	eat_time;

	pthread_mutex_lock(&data->mut_eat_time);
	eat_time = data->eat_time;
	pthread_mutex_unlock(&data->mut_eat_time);
	return (eat_time);
}

uint64_t	get_last_time_eat(t_philo *philo)
{
	uint64_t	last_eat_time;

	pthread_mutex_lock(&philo->mut_last_time_eat);
	last_eat_time = philo->last_time_eat;
	pthread_mutex_unlock(&philo->mut_last_time_eat);
	return (last_eat_time);
}
