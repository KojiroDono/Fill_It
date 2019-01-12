# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: auguyon <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 15:44:37 by auguyon           #+#    #+#              #
#    Updated: 2019/01/09 15:26:36 by auguyon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRCS	=	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
			ft_isdigit.c ft_isprint.c ft_isspace.c ft_isblank.c\
			ft_isctrl.c ft_isgraph.c ft_islower.c ft_ispunct.c ft_isupper.c\
			ft_memcpy.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memmove.c\
			ft_memset.c ft_strcat.c ft_strchr.c ft_strcmp.c ft_strnew.c\
			ft_strcpy.c ft_strdup.c ft_strndup.c ft_strlcat.c ft_strlen.c\
			ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnstr.c ft_strrchr.c\
			ft_strstr.c ft_tolower.c ft_toupper.c ft_memalloc.c ft_memdel.c\
			ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c\
			ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c\
			ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c\
			ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_lstadd.c ft_lstdel.c\
			ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c\
			ft_putstr_fd.c ft_lstiter.c ft_lstmap.c ft_strspn.c ft_strcspn.c\
			ft_strmultidel.c ft_putmultistr.c ft_strnjoin.c
			
OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra -I $(LIB)

LIB		=	libft.h

RM		=	rm -rf

all		:	$(NAME)

$(NAME)	:	$(OBJS) $(LIB)
			ar rc $(NAME) $(OBJS)

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

recl	:	all clean
