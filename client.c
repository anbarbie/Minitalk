/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 22:42:17 by antbarbi          #+#    #+#             */
/*   Updated: 2021/09/20 20:21:17 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int		g_ack;

static	void	rec_ack(int signum)
{
	if (signum == SIGUSR1)
		g_ack = 1;
	return ;
}

static	void	send_binary(char c, int pid)
{
	int		i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
		i--;
	}
}

int	main(int ac, char **av)
{
	char	*str;
	int		pid;

	g_ack = 0;
	signal(SIGUSR1, rec_ack);
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		str = av[2];
		while (*str)
		{
			send_binary(*str, pid);
			str++;
		}
		send_binary('\0', pid);
		if (g_ack == 1)
			ft_putendl_fd("Message received!", 1);
	}
	else
		ft_putstr_fd("Error\nWrong number of arguments\n", 1);
	return (0);
}
