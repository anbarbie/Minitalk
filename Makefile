# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/17 02:43:38 by antbarbi          #+#    #+#              #
#    Updated: 2021/08/17 02:43:38 by antbarbi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1= server

NAME2= client

SRCS= srcs/ft_atoi.c srcs/ft_bzero.c srcs/ft_memset.c srcs/ft_putchar_fd.c \
srcs/ft_putendl_fd.c srcs/ft_putnbr_fd.c  srcs/ft_putstr_fd.c

all :
	gcc -Wall -Wextra -Werror -o $(NAME1) server.c $(SRCS)
	gcc -Wall -Wextra -Werror -o $(NAME2) client.c $(SRCS)

clean :
	rm -rf client.o server.o

fclean : clean
	rm -rf $(NAME1) $(NAME2)

re : fclean all