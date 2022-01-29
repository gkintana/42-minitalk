/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:08:22 by gkintana          #+#    #+#             */
/*   Updated: 2022/01/29 17:17:44 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

static int	ft_verify_args(pid_t pid, char *str)
{
	if (!(pid > MIN_PID && pid < MAX_PID))
		return (1);
	if (!str || !*str)
		return (1);
	return (0);
}

static void	ft_terminate_connection(int bytes)
{
	ft_printf(YELLOW MTC_RECEIVED"\n", bytes);
	exit(EXIT_SUCCESS);
}

static void	ft_send_bit(pid_t pid, char *str, int bytes)
{
	static int		i = 0;
	static int		bit = 8;
	static char		*string = 0;
	static char		ptr = 0;
	static pid_t	serv_pid = 0;

	if (str)
	{
		string = str;
		ptr = string[i];
		serv_pid = pid;
	}
	if (!bit)
	{
		bit = 8;
		ptr = string[++i];
	}
	usleep(50);
	if (!ptr)
		ft_terminate_connection(bytes);
	else if (ptr >> --bit & 1)
		kill(serv_pid, SIGUSR1);
	else
		kill(serv_pid, SIGUSR2);
}

static void	ft_signal_handler(int sig)
{
	static int	bytes = 0;

	if (sig == SIGUSR1)
		++bytes;
	ft_send_bit(0, NULL, bytes);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		if (argc < 3)
			ft_printf(RED MTC_BOOT_KO1"\n"MTC_ARGS_KO"\n"MTC_TERM"\n");
		else
			ft_printf(RED MTC_BOOT_KO2"\n"MTC_ARGS_KO"\n"MTC_TERM"\n");
		return (1);
	}
	ft_printf(GREEN MTC_BOOT_OK"\n");
	if (ft_verify_args(ft_atoi(argv[1]), argv[2]))
	{
		ft_printf(RED MTC_ARGS_INC"\n"MTC_TERM"\n");
		return (1);
	}
	ft_printf(GREEN MTC_PID_OK"\n"BLUE MTC_UPLOAD"\n");
	signal(SIGUSR1, ft_signal_handler);
	signal(SIGUSR2, ft_signal_handler);
	ft_printf(YELLOW MTC_SENT"\n", (int)ft_strlen(argv[2]));
	ft_send_bit(ft_atoi(argv[1]), argv[2], 0);
	while (1)
		pause();
	return (0);
}
