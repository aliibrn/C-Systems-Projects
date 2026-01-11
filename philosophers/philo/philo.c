/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:05:58 by abbouram          #+#    #+#             */
/*   Updated: 2024/07/25 17:06:00 by abbouram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lunch_the_dinner(t_dinner *dinner)
{
	t_dinner	*join;
	t_dinner	*for_monitor;
	pthread_t	monitor;

	join = dinner;
	for_monitor = dinner;
	pthread_create(&monitor, NULL, &ft_monitor, for_monitor);
	while (dinner)
	{
		pthread_create(&dinner->philo.thread, NULL, &the_dinner, dinner);
		dinner = dinner->next;
	}
	pthread_join(monitor, NULL);
	while (join)
	{
		pthread_join(join->philo.thread, NULL);
		join = join->next;
	}
}

int	main(int ac, char **av)
{
	t_dinner	*dinner;
	int			*data;

	dinner = NULL;
	if (ac == 5 || ac == 6)
	{
		data = return_numbers(av);
		if (data)
		{
			if (init(&dinner, data, ac))
			{
				lunch_the_dinner(dinner);
				ft_clean(dinner, data);
			}
		}
		else
			ft_putendl_fd("PLEASE ENTER A VALID ARG", 2);
	}
	else
		ft_putendl_fd("PLEASE ENTER A VALID ARG", 2);
}
