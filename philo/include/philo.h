/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:40:15 by ssteveli          #+#    #+#             */
/*   Updated: 2024/04/01 13:40:15 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdint.h>
# include <stdbool.h>
# include <unistd.h>

typedef enum e__philo_state
{
	EATING = 0,
	SLEEPING = 1,
	THINKING = 2,
	DEAD = 3,
	FULL = 4,
	IDLE = 5
}	t_state;

struct s_data;

typedef struct s_philo
{
	int				id;
	int				number_meals_eat;
	u_int64_t		last_time_eat;
	struct s_data	*data;
	t_state			state;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t mut_state;
	pthread_mutex_t mut_number_meals_eat;
	pthread_mutex_t mut_last_time_eat;
}t_philo;

typedef struct s_data
{
	int				number_philos;
	int				number_meals;
	int				nb_full_p;
	bool			keep_iterating;
	u_int64_t		eat_time;	
	u_int64_t		die_time;	
	u_int64_t		sleep_time;	
	u_int64_t		start_time;	
	pthread_mutex_t	mut_eat_time;
	pthread_mutex_t	mut_die_time;
	pthread_mutex_t	mut_sleep_time;
	pthread_mutex_t	mut_print;
	pthread_mutex_t	mut_number_philos;
	pthread_mutex_t	mut_keep_iter;
	pthread_mutex_t	mut_start_time;
	pthread_mutex_t *forks;
	pthread_t		monit_all_alive;
	pthread_t		*philo_thread;
	pthread_t		monit_all_full;
	t_philo			*philos;
}t_data;

void		*cycle(void *philo_p);
bool		philo_died(t_philo *philo);
int			check_input(int argc, char **argv);
int			wrong_input(int argc, char **argv);
int			ft_atoi(char *str);
int			init_data(t_data *data, int argc, char **argv);
int			init_philos(t_data *data);
int			init_forks(t_data *data);
u_int64_t	get_time(void);
void		ft_usleep(uint64_t time);
void		*all_full(void *data_p);
void		*all_alive(void *data_p);
int			eat(t_philo *philo);
void		update_last_time_eat(t_philo *philo);
int			take_forks(t_philo *philo);
int			take_right_fork(t_philo *philo);
int			take_left_fork(t_philo *philo);
void		drop_right_fork(t_philo *philo);
int			ft_sleep(t_philo *philo);
int			think(t_philo *philo);
uint64_t	get_die_time(t_data *data);
uint64_t	get_eat_time(t_data *data);
uint64_t	get_sleep_time(t_data *data);
bool		get_keep_iter(t_data *data);
uint64_t	get_start_time(t_data *data);
int			get_number_philos(t_data *data);
t_state		get_philo_state(t_philo *philo);
int			get_number_meals_eat(t_philo *philo);
uint64_t	get_last_time_eat(t_philo *philo);
void		set_keep_iterating(t_data *data, bool set_to);
void		set_philo_state(t_philo *philo, t_state state);
bool		number_meals_option(t_data *data);
void		free_data(t_data *data);
void		print_msg(t_data *data, int id, char *msg);
int			ft_1_philo(t_philo *philo);

#endif