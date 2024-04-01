/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:26:02 by ssteveli          #+#    #+#             */
/*   Updated: 2024/04/01 14:26:02 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	get_keep_iter(t_data *data)
{
	bool	keep_iterating;

	pthread_mutex_lock(&data->mut_keep_iter);
	keep_iterating = data->keep_iterating;
	pthread_mutex_unlock(&data->mut_keep_iter);
	return (keep_iterating);
}

int	get_number_philos(t_data *data)
{
	int	nb_philos;

	pthread_mutex_lock(&data->mut_number_philos);
	nb_philos = data->number_philos;
	pthread_mutex_unlock(&data->mut_number_philos);
	return (nb_philos);
}

t_state	get_philo_state(t_philo *philo)
{
	t_state	state;

	pthread_mutex_lock(&philo->mut_state);
	state = philo->state;
	pthread_mutex_unlock(&philo->mut_state);
	return (state);
}

int	get_number_meals_eat(t_philo *philo)
{
	int	nb_meals_had;

	pthread_mutex_lock(&philo->mut_number_meals_eat);
	nb_meals_had = philo->number_meals_eat;
	pthread_mutex_unlock(&philo->mut_number_meals_eat);
	return (nb_meals_had);
}

uint64_t	get_start_time(t_data *data)
{
	uint64_t	time;

	pthread_mutex_lock(&data->mut_start_time);
	time = data->start_time;
	pthread_mutex_unlock(&data->mut_start_time);
	return (time);
}