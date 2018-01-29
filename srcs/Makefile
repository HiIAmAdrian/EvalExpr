# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adstan <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/03 20:02:09 by adstan            #+#    #+#              #
#    Updated: 2017/09/03 20:25:32 by adstan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


all:
	@gcc -Wall -Wextra -Werror -c main.c ft_func.c ft_func2.c eval_expr.c proc.c stack.c ft_list.c
	@gcc -o eval_expr main.o ft_func.o ft_func2.o eval_expr.o proc.o stack.o ft_list.o

clean:
	@rm -f eval_expr main.o ft_func.o ft_func2.o eval_expr.o proc.o stack.o ft_list.o

fclean: clean
	@rm -f eval_expr
	
re: fclean all
