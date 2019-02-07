# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sregnard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 14:51:18 by sregnard          #+#    #+#              #
#    Updated: 2019/02/05 16:03:10 by sregnard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libftprintf.a

HEADDIR			=	includes/
HEADERS			=	-I $(HEADDIR)

SRCDIR			=	srcs/
SRCNAME			= 	ft_printf.c \
					pf_parse_args.c \
					pf_strlen.c \
					pf_putchar.c \
					pf_putstr.c \
					pf_putnbr.c \
					pf_atoi.c \
					pf_putaddr.c
SRC				=	$(addprefix $(SRCDIR), $(SRCNAME))

OBJDIR			=	objs/
OBJ				=	$(SRC:$(SRCDIR)%.c=$(OBJDIR)%.o)
	
CC				=	gcc	
CFLAGS			=	-Wall -Wextra -Werror
XFLAGS			=	

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
