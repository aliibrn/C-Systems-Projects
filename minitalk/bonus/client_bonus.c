/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 02:04:29 by abbouram          #+#    #+#             */
/*   Updated: 2024/04/06 02:12:18 by abbouram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk_bonus.h"

void	sendcharbitstoserver(char ch, int pid)
{
	int		i;
	char	tmp;
	int		bit;

	i = 7;
	while (i >= 0)
	{
		tmp = (ch >> i);
		bit = tmp & 1;
		if (bit == 1)
		{
			kill(pid, SIGUSR1);
		}
		else if (bit == 0)
		{
			kill(pid, SIGUSR2);
		}
		usleep(200);
		i--;
	}
}

void	checkmsg(int sig)
{
	(void)sig;
	ft_printf("received\n");
}

int	main(int ac, char **av)
{
	int					pid;
	int					i;
	char				*str;
	struct sigaction	sa_client;

	if (ac == 3 && check_args(av))
	{
		pid = check_args(av);
		i = 0;
		str = av[2];
		sa_client.sa_handler = &checkmsg;
		sigaction(SIGUSR1, &sa_client, NULL);
		if (!check_process(pid))
		{
			while (str[i])
			{
				sendcharbitstoserver(str[i], pid);
				i++;
			}
			sendcharbitstoserver('\n', pid);
		}
	}
}
