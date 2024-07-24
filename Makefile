# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/19 18:55:58 by tcohen            #+#    #+#              #
#    Updated: 2024/07/20 19:59:19 by tcohen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

INCLUDES = -I .

FUNC = $(addprefix ft_, $(addsuffix .c, big_sort \
		check \
		cost \
		nbr \
		small_sort \
		split \
		str \
		target \
		treatment))

CLIST =	$(addprefix c_list/ft_, $(addsuffix .c, lstaddback \
		lstaddfront \
		lstclear \
		lstfirst \
		lstlast \
		lstnew \
		lstsize \
		makelist \
		lstone))
		
COMMAND = $(addprefix command_ps/ft_, $(addsuffix .c, stack \
		double_stack))


SRCS = $(FUNC) $(CLIST) $(COMMAND) push_swap.c

OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ 


$(NAME) : $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

all : $(NAME)

clean : 
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re