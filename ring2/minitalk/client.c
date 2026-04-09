#include "minitalk.h"

volatile sig_atomic_t	acknowledgement = 0;

void	ack_handler(int sig)
{
	(void)sig;
	acknowledgement = 1;
}

void	send_char(int server_pid, unsigned char character)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		acknowledgement = 0;
		if ((character >> bit) & 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		bit--;
		while (!acknowledgement)
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
    {
        ft_putstr_fd("Usage: ./client [Server PID] [String]\n",1);
        return (1);
    }
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
