/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 02:04:37 by abbouram          #+#    #+#             */
/*   Updated: 2024/04/06 02:04:38 by abbouram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk_bonus.h"

void	send_signal_to_client(int pid, char c)
{
	if (c == '\n')
		kill(pid, SIGUSR1);
}

void	handle_signal(int signal, siginfo_t *info, void *ucontext)
{
	int						pid;
	static unsigned char	received_char = 0;
	static int				bit_index = 0;

	pid = info->si_pid;
	(void)ucontext;
	received_char |= (signal == SIGUSR1);
	bit_index++;
	if (bit_index == 8)
	{
		ft_printf("%c", received_char);
		send_signal_to_client(pid, received_char);
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
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handle_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
	}
}
