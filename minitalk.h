/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 21:10:26 by antbarbi          #+#    #+#             */
/*   Updated: 2021/09/20 20:26:50 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "./libft/libft.h"
# define BUFFER 1024

typedef struct s_buff
{
	char			str[BUFFER];
	int				cpt;
}					t_buff;

#endif
