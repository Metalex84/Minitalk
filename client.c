/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejango <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:10:12 by alejango          #+#    #+#             */
/*   Updated: 2025/01/28 20:38:55 by alejango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile sig_atomic_t	g_bit_received = 0;

static void	sig_handler(int signum)
{
	(void)signum;
	g_bit_received = 1;
}

static int	validate_pid(char *pid)
{
	int	i;

	i = 0;
	while (pid[i])
	{
		if (!ft_isdigit(pid[i++]))
			return (0);
	}
	return (1);
}

static void	send_char(pid_t server_pid, unsigned char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		g_bit_received = 0;
		if ((c >> bit) & 1)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		while (!g_bit_received)
			;
		bit--;
	}
}

static int	send_message(pid_t server_pid, char *message)
{
	if (kill(server_pid, 0) != 0)
		return (0);
	else
	{
		while (*message)
		{
			send_char(server_pid, *message);
			message++;
		}
		send_char(server_pid, '\0');
		return (1);
	}
}

int	main(int argc, char **argv)
{
	pid_t				server_pid;
	struct sigaction	sa;

	if (argc != 3 || !ft_strlen(argv[2]) || !validate_pid(argv[1]))
	{
		ft_printf("ERROR\nUsage: ./client <server_pid> <message>\n");
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	sa.sa_handler = sig_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	ft_printf("Sending message to PID server: %d\n", server_pid);
	if (!send_message(server_pid, argv[2]))
		ft_printf("ERROR: no processes running with PID %d\n", server_pid);
	else
		ft_printf("WELL DONE: message sent to process %d\n", server_pid);
	return (0);
}
