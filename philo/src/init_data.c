/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:26:51 by ssteveli          #+#    #+#             */
/*   Updated: 2024/04/01 14:26:51 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int init_forks(t_data *data)
{
    int i;
    t_philo *philos;

    philos = data->philos;
    i = -1;
    while (++i < data->number_philos)
        pthread_mutex_init(&data->forks[i], NULL);
    i = 0;
    philos[0].left_fork = &data->forks[0];
    philos[0].right_fork = &data->forks[data->number_philos - 1];
    while (++i < data->number_philos)
    {
        philos[i].left_fork = &data->forks[i];
        philos[i].right_fork = &data->forks[i - 1];
    }
    return (0);
}

int init_philos(t_data *data)
{
    t_philo *philos;
    int     i;

    i = -1;
    philos = data->philos;
    while (++i < data->number_philos)
    {
        philos[i].data = data;
        philos[i].id = i + 1;
        philos[i].number_meals_eat = 0;
        philos[i].state = IDLE;
        pthread_mutex_init(&philos[i].mut_state, NULL);
        pthread_mutex_init(&philos[i].mut_number_meals_eat, NULL);
        pthread_mutex_init(&philos[i].mut_last_time_eat, NULL);
        update_last_time_eat(&philos[i]);    
    }
    return (0);
}

int malloc_data(t_data *data)
{
    data->philos = malloc(sizeof(t_philo) * data->number_philos);
	if (data->philos == NULL)
		return (2);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->number_philos);
	if (data->forks == NULL)
		return (free(data->philos), 2);
	data->philo_thread = malloc(sizeof(pthread_t) * data->number_philos);
	if (data->philo_thread == NULL)
		return (free(data->philos), free(data->forks), 2);
	return (0);
}

int	init_data(t_data *data, int argc, char **argv)
{
	data->nb_full_p = 0;
	data->keep_iterating = true;
	data->number_philos = ft_atoi(argv[1]);
	data->die_time = (u_int64_t) ft_atoi(argv[2]);
	data->eat_time = (u_int64_t) ft_atoi(argv[3]);
	data->sleep_time = (u_int64_t) ft_atoi(argv[4]);
	data->number_meals = -1;
	if (argc == 6)
		data->number_meals = ft_atoi(argv[5]);
	pthread_mutex_init(&data->mut_eat_time, NULL);
	pthread_mutex_init(&data->mut_sleep_time, NULL);
	pthread_mutex_init(&data->mut_die_time, NULL);
	pthread_mutex_init(&data->mut_print, NULL);
	pthread_mutex_init(&data->mut_number_philos, NULL);
	pthread_mutex_init(&data->mut_keep_iter, NULL);
	pthread_mutex_init(&data->mut_start_time, NULL);
	return (malloc_data(data));
}