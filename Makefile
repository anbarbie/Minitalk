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

LIB= libft/libft.a

all :
	make -C libft
	gcc -Wall -Wextra -Werror -o $(NAME1) server.c $(LIB)
	gcc -Wall -Wextra -Werror -o $(NAME2) client.c $(LIB)

clean :
	make clean -C libft
	rm -rf client.o server.o

fclean : clean
	make fclean -C libft
	rm -rf $(NAME1) $(NAME2)

re : fclean all