/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 07:24:06 by carmarqu          #+#    #+#             */
/*   Updated: 2024/01/09 10:16:45 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	init_mutex(t_data *data)
{
	int	x;

	x = 0;
	pthread_mutex_init(&data->write, NULL);
	pthread_mutex_init(&data->done, NULL);
	pthread_mutex_init(&data->lap, NULL);
	while (x < data->num_philo)
	{
		pthread_mutex_init(&data->forks[x], NULL);
		x++;
	}
	data->philo[0].r_fork = &data->forks[data->num_philo - 1];
	data->philo[0].l_fork = &data->forks[0];
	x = 1;
	while (x < data->num_philo)
	{
		data->philo[x].l_fork = &data->forks[x];
		data->philo[x].r_fork = &data->forks[x - 1];
		x++;
	}
	return (1);
}

int	init_philos(t_data *data)
{
	int	x;

	x = 0;
	while (x < data->num_philo)
	{
		data->philo[x].laps = 0;
		data->philo[x].data = data;
		data->philo[x].id = x + 1;
		data->tid[x] = data->philo[x].t1;
		data->philo[x].last_meal = 0;
		x++;
	}
	return (1);
}

int	init_mem(t_data *data)
{
	data->philo = malloc(sizeof(t_philo) * data->num_philo);
	if (!data->philo)
		return (0);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philo);
	if (!data->forks)
		return (0);
	data->tid = malloc(sizeof(pthread_t) * data->num_philo);
	if (!data->tid)
		return (0);
	return (1);
}

int	init_data(t_data *data, int argc, char **argv)
{
	if (!check_args(argc, argv))
		return (0);
	(*data).num_philo = ft_atoi(argv[1]);
	(*data).death_time = ft_atoi(argv[2]);
	(*data).eat_time = ft_atoi(argv[3]);
	(*data).sleep_time = ft_atoi(argv[4]);
	if (argc == 6)
		(*data).final_lap = ft_atoi(argv[5]);
	else
		(*data).final_lap = -1;
	(*data).start_time = get_time();
	data->break_flag = 0;
	init_mem(data);
	init_mutex(data);
	init_philos(data);
	return (1);
}
