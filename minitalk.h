/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 21:10:26 by antbarbi          #+#    #+#             */
/*   Updated: 2021/08/16 21:10:26 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "./libft/libft.h"
# define BUFFER 1000

typedef struct		sbuff
{
	char			str[BUFFER];
	unsigned char	set;
	int				cpt;
}					tbuff;

#endif