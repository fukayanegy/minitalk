#include "../include/minitalk.h"

/*
struct sigaction {
	void		(*sa_handler)(int);
	void		(*sa_sigaction)(int, siginfo_t *, void *);
	sigset_t	sa_mask;
	int			sa_flags;
	void		(*sa_restorer)(void);
};
*/

static void	action(int sig, siginfo_t *info, void *context)
{
	static int				i = 0;
	static pid_t			client_pid = 0;
	static unsigned char	c = '\0';

	(void)context;
	if (!client_pid)
	{
		client_pid = info->si_pid;
	}
	c |= (sig == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		if (c == '\0')
		{
			kill(client_pid, SIGUSR2);
			client_pid = 0;
			return ;
		}
		printf("%c", c);
		c = '\0';
		kill(client_pid, SIGUSR1);
	}
	else
		c <<= 1;
}

int	main(void)
{
	struct sigaction	s_sigaction;
	int					pid;

	pid = getpid();
	printf("Server POD: %d\n", pid);
	s_sigaction.sa_sigaction = action;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (true)
		pause();
	return (0);
}
