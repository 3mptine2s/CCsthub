/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chutterm <chutterm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 16:39:28 by chutterm          #+#    #+#             */
/*   Updated: 2026/03/30 17:44:26 by chutterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

/*
** Using the advanced handler signature required by SA_SIGINFO.
** info->si_pid contains the Process ID of the client that sent the signal.
*/
void	reconstruct_char(int sig, siginfo_t *info, void *context)
{
	static unsigned char	current_char;
	static int				bit_count;

	(void)context;
	current_char = current_char << 1;
	if (sig == SIGUSR1)
		current_char |= 1;
	bit_count++;
	if (bit_count == 8)
	{
		if (current_char == '\0')
			write(1, "\n", 1);
		else
			write(1, &current_char, 1);
		bit_count = 0;
		current_char = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	int					server_pid;
	struct sigaction	sa;

	server_pid = getpid();
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(server_pid, 1);
	ft_putstr_fd("\nWaiting for signal...\n", 1);
	sa.sa_sigaction = reconstruct_char;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
