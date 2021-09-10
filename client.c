/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 22:42:17 by antbarbi          #+#    #+#             */
/*   Updated: 2021/08/16 22:42:17 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void		send_binary(char c, int pid)
{
	int		i;

	i = 0;
	while (i++ < 8)
	{
		if (c & 0x01)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		c = c >> 1;
		usleep(100);
	}
}

int				main(int ac, char **av)
{
	char	*str;
	int		pid;

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
	}
	else
		ft_putstr_fd("Error\nWrong number of arguments\n", 1);
	return (0);
}