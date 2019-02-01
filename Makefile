# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sregnard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 14:51:18 by sregnard          #+#    #+#              #
#    Updated: 2019/02/01 15:45:08 by sregnard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libftprintf.a

HEADDIR			=	includes/
HEADERS			=	-I $(HEADDIR)

SRCDIR			=	srcs/
SRCNAME			= 	ft_printf.c \
					ft_strlen.c \
					ft_putchar.c \
					ft_putstr.c \
					ft_putnbr.c \
					ft_putaddr.c
SRC				=	$(addprefix $(SRCDIR), $(SRCNAME))

OBJDIR			=	objs/
OBJ				=	$(SRC:$(SRCDIR)%.c=$(OBJDIR)%.o)
	
CC				=	gcc	
CFLAGS			=	-Wall -Wextra -Werror
XFLAGS			=	-g3

all				:	$(OBJDIR) $(NAME)

$(NAME)			:	$(OBJ)
	ar rcs $@ $(OBJ)
	  
$(OBJDIR)		:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o	:	$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $^

clean			:	
	rm -rf $(OBJDIR)*.o

fclean			:	clean
	rm -rf $(NAME)

re				: fclean all

.PHONY			:	all clean fclean re
