/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:08:22 by gkintana          #+#    #+#             */
/*   Updated: 2022/01/29 17:17:40 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

static void	ft_signal_handler(int sig, siginfo_t *info, void *context)
{
	static int		bit = 0;
	static char		chr = 0;

	(void)context;
	chr |= (sig == SIGUSR1);
	if (++bit == 8)
	{
		bit = 0;
		ft_putchar_fd(chr, 1);
		chr = 0;
		kill (info -> si_pid, SIGUSR1);
	}
	else
	{
		chr <<= 1;
		kill (info -> si_pid, SIGUSR2);
	}
}

int	main(void)
{
	struct sigaction	mem;

	ft_printf(GREEN MTS_BOOT"\n"MTS_SPID"\n", getpid());
	mem.sa_flags = SA_SIGINFO;
	mem.sa_sigaction = ft_signal_handler;
	sigaction(SIGUSR1, &mem, NULL);
	sigaction(SIGUSR2, &mem, NULL);
	ft_printf(BLUE MTS_AMCI"\n");
	while (1)
		pause();
	return (0);
}
