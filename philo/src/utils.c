/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:52:55 by ssteveli          #+#    #+#             */
/*   Updated: 2024/04/01 14:52:55 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_1_philo(t_philo *philo)
{
	take_left_fork(philo);
	ft_usleep(get_die_time(philo->data));
	set_philo_state(philo, DEAD);
	return (1);
}

bool	number_meals_option(t_data *data)
{
	if (data->number_meals > 0)
		return (true);
	return (false);
}

void	free_data(t_data *data)
{
	int	i;
	int	nb_philos;

	nb_philos = get_number_philos(data);
	i = -1;
	while (++i < nb_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].mut_state);
		pthread_mutex_destroy(&data->philos[i].mut_number_meals_eat);
		pthread_mutex_destroy(&data->philos[i].mut_last_time_eat);
	}
	pthread_mutex_destroy(&data->mut_die_time);
	pthread_mutex_destroy(&data->mut_eat_time);
	pthread_mutex_destroy(&data->mut_sleep_time);
	pthread_mutex_destroy(&data->mut_number_philos);
	pthread_mutex_destroy(&data->mut_print);
	pthread_mutex_destroy(&data->mut_keep_iter);
	pthread_mutex_destroy(&data->mut_start_time);
	free(data->philo_thread);
	free(data->philos);
	free(data->forks);
}

void	print_msg(t_data *data, int id, char *msg)
{
	uint64_t	time;

	time = get_time() - get_start_time(data);
	pthread_mutex_lock(&data->mut_print);
	if (get_keep_iter(data))
		printf("%lu %d %s\n", time, id, msg);
	pthread_mutex_unlock(&data->mut_print);
}
