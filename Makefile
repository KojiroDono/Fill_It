# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: auguyon <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/11 14:00:25 by auguyon           #+#    #+#              #
#    Updated: 2018/12/28 15:11:57 by auguyon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fillit

SRCS	=	alloc_map.c main.c sort_tab.c parse.c special_tetra_check.c solver.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	= 	-Wall -Werror -Wextra -I -ILibft

LIB		=	Libft/libft.a

RM		=	rm -rf

all		:	$(NAME)

$(NAME)	:	$(OBJS) $(LIB)
			$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

$(LIB):
			make -C libft/
clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(OBJS)

re		:	fclean all

recl	:	all clean
