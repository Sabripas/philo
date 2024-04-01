/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:43:46 by ssteveli          #+#    #+#             */
/*   Updated: 2024/04/01 14:43:46 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	run_threads(t_data *data)
{
	int	i;
	int	nb_of_philos;

	nb_of_philos = get_number_philos(data);
	i = -1;
	data->start_time = get_time();
	while (++i < nb_of_philos)
	{
		if (pthread_create(&data->philo_thread[i], NULL,
				&cycle, &data->philos[i]))
			return (1);
	}
	if (pthread_create(&data->monit_all_alive, NULL,
			&all_alive, data))
		return (1);
	if (number_meals_option(data) == true
		&& pthread_create(&data->monit_all_full, NULL,
			&all_full, data))
		return (1);
	return (0);
}

int	join_threads(t_data *data)
{
	int	i;
	int	nb_philos;

	nb_philos = get_number_philos(data);
	i = -1;
	if (pthread_join(data->monit_all_alive, NULL))
		return (1);
	if (number_meals_option(data) == true
		&& pthread_join(data->monit_all_full, NULL))
		return (1);
	while (++i < nb_philos)
	{
		if (pthread_join(data->philo_thread[i], NULL))
			return (1);
	}
	return (0);
}

int	philosophers(int argc, char **argv)
{
	t_data	data;

	if (init_data(&data, argc, argv) != 0)
		return (2);
	init_philos(&data);
	init_forks(&data);
	run_threads(&data);
	join_threads(&data);
	free_data(&data);
	return (0);
}

int	main(int argc, char **argv)
{
	if (check_input(argc, argv) != 0)
	{
		printf("Wrong input");
		return (1);
	}
	if (philosophers(argc, argv) != 0)
		return (2);
	return (0);
}