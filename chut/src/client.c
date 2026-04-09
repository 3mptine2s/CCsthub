/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chutterm <chutterm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 16:38:27 by chutterm          #+#    #+#             */
/*   Updated: 2026/03/30 17:45:07 by chutterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

// Global flag to track if we received the server's acknowledgment
volatile sig_atomic_t	g_ack_received = 0;

/*
** A simple handler that flip the flag
*/
void	ack_handler(int sig)
{
	(void)sig;
	g_ack_received = 1;
}

void	send_char(int server_pid, unsigned char character)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		g_ack_received = 0;
		if ((character >> bit) & 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		bit--;
		while (!g_ack_received)
			pause();
	}
}

void	send_message(int server_pid, char *str)
{
	while (*str != '\0')
	{
		send_char(server_pid, (unsigned char)*str);
		str++;
	}
	send_char(server_pid, '\0');
}

int	main(int argc, char **argv)
{
	int					server_pid;
	struct sigaction	sa;

	if (argc != 3)
		return (1);
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
		return (1);
	sa.sa_handler = ack_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	send_message(server_pid, argv[2]);
	return (0);
}
