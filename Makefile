# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: auguyon <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/11 14:00:25 by auguyon           #+#    #+#              #
#    Updated: 2019/01/09 15:21:37 by auguyon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fillit

SRCS	=	alloc_map.c error.c main.c open_n_read.c parse.c print_in_color.c\
			solver.c sort_tab.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	= 	-Wall -Werror -Wextra -I -ILibft

LIB		=	Libft/libft.a

RM		=	rm -rf

all		:	$(NAME)

$(NAME)	:	$(OBJS) $(LIB)
			$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

$(LIB):
			make recl -C libft/
clean	:
			$(RM) $(OBJS)
			make clean -C libft/

fclean	:	clean
			$(RM) $(NAME)
			make fclean -C libft/

re		:	fclean all

recl	:	all clean
