# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: auguyon <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/11 14:00:25 by auguyon           #+#    #+#              #
#    Updated: 2018/12/12 11:39:50 by auguyon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fillit

SRCS	=	check_error.c main.c parse.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra -I -ILibft/ 	#-O1 2 3

LIB		=	Libft/libft.a

RM		=	rm -rf

all		:	$(NAME)

$(NAME)	:	$(OBJS) $(LIB)
			$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

$(LIB):
			make -C Libft/
clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(OBJS)

re		:	fclean all

recl	:	all clean
