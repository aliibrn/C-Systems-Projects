/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 02:04:16 by abbouram          #+#    #+#             */
/*   Updated: 2024/04/06 02:04:17 by abbouram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	handle_signal(int signal)
{
	static unsigned char	received_char = 0;
	static int				bit_index = 0;

	received_char |= (signal == SIGUSR1);
	bit_index++;
	if (bit_index == 8)
	{
		ft_printf("%c", received_char);
		bit_index = 0;
		received_char = 0;
	}
	else
		received_char <<= 1;
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("%d\n", pid);
	sa.sa_handler = &handle_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
	}
}
