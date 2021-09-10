/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 21:09:21 by antbarbi          #+#    #+#             */
/*   Updated: 2021/08/16 21:09:21 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

tbuff s;

static	void 	set_struct()
{
	ft_memset(s.str, 0, s.cpt);
	s.set = 128;
	s.cpt = 0;
}

static 	void	sig_handler(int signum)
{
	static int		i = 0;
	static unsigned char		tmp = 0;

	if (signum == SIGUSR2)
		tmp |= s.set;
	if (i == 7)
	{
		s.str[s.cpt] = tmp;
		i = -1;
		s.cpt++;
		if (s.cpt == BUFFER || s.str[s.cpt - 1] == '\0')
		{
			ft_putendl_fd(s.str, 1);
			set_struct();
		}
	}
	tmp = tmp >> 1;
	i++;
}

int		main(void)
{	
	struct sigaction	sa;

	sa.sa_handler = sig_handler;
	sa.sa_flags = SA_SIGINFO;
	set_struct();
	ft_memset(s.str, 0, BUFFER);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putstr_fd("PID = ", 1);
	ft_putnbr_fd((int)getpid(), 1);
	ft_putstr_fd("\n", 1);
	while (1)
		usleep(100);
	return (0);
}