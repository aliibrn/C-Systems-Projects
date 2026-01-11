/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:06:49 by abbouram          #+#    #+#             */
/*   Updated: 2024/07/25 17:06:51 by abbouram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	destroy_data(t_data *data)
{
	if (data)
	{
		if (data->print)
		{
			pthread_mutex_destroy(data->print);
			free(data->print);
		}
		if (data->monitor)
		{
			pthread_mutex_destroy(data->monitor);
			free(data->monitor);
		}
		if (data->meal)
		{
			pthread_mutex_destroy(data->meal);
			free(data->meal);
		}
		free(data);
	}
}

void	init_the_dinner(t_dinner *dinner)
{
	t_dinner	*temp;
	t_dinner	*left;

	temp = dinner;
	while (dinner)
	{
		dinner->philo.eat = 0;
		dinner->philo.own = malloc(sizeof(t_mutex));
		dinner->philo.last_meal = dinner->data->creation_time;
		pthread_mutex_init(&dinner->philo.own->fork, NULL);
		dinner = dinner->next;
	}
	while (temp)
	{
		left = return_the_left(temp);
		temp->philo.left = left->philo.own;
		temp = temp->next;
	}
}

void	init_the_data(t_data *data)
{
	data->creation_time = ft_time();
	data->finish = false;
	data->all_ate = 0;
	data->print = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(data->print, NULL);
	data->monitor = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(data->monitor, NULL);
	data->meal = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(data->meal, NULL);
}

int	creat_the_table(t_dinner **dinner, int philo_num, t_data *data)
{
	int	i;
	int	y;

	y = 1;
	i = 0;
	init_the_data(data);
	if (data->num_of_times_each_philo_must_eat == 0 || data->time_to_eat == -2
		|| data->time_to_sleep == -2 || data->time_to_die == -2
		|| data->philo_num == -2)
		return (0);
	if (philo_num > 0)
	{
		while (i < philo_num)
		{
			creat_nodes(dinner, y, data);
			y++;
			i++;
		}
		init_the_dinner(*dinner);
		return (1);
	}
	return (0);
}

int	init(t_dinner **dinner, int *data, int ac)
{
	t_data	*philo_data;

	philo_data = malloc(sizeof(t_data));
	philo_data->philo_num = data[0];
	philo_data->time_to_die = data[1];
	philo_data->time_to_eat = data[2];
	philo_data->time_to_sleep = data[3];
	if (ac == 6)
		philo_data->num_of_times_each_philo_must_eat = data[4];
	else
		philo_data->num_of_times_each_philo_must_eat = -1;
	if (creat_the_table(dinner, philo_data->philo_num, philo_data))
		return (1);
	else
	{
		destroy_data(philo_data);
		if (data)
			free(data);
	}
	return (0);
}
