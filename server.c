/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejango <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:09:26 by alejango          #+#    #+#             */
/*   Updated: 2025/01/28 21:00:13 by alejango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	signal_handler(int signal, siginfo_t *sinfo, void *content)
{
	static unsigned char	character = 0;
	static int				bit_count = 0;

	(void)content;
	if (sinfo->si_pid == 0)
		return ;
	character |= (signal == SIGUSR2);
	bit_count++;
	if (bit_count == 8)
	{
		if (character == '\0')
			ft_printf("\nGot tha message. Tell me more!\n");
		else
			ft_printf("%c", character);
		character = 0;
		bit_count = 0;
	}
	else
		character = character << 1;
	kill(sinfo->si_pid, SIGUSR1);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("Server running on PID: %d and listening!\n", pid);
	ft_printf("Waiting for messages...\n");
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
