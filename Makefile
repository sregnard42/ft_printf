# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sregnard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 14:51:18 by sregnard          #+#    #+#              #
#    Updated: 2019/02/10 15:31:37 by sregnard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libftprintf.a
LIBFT			=	libft/libft.a

HEADERS			=	-I includes/
HEADERS			+=	-I libft/includes/

SRCDIR			=	srcs/
SRCNAME			= 	ft_printf.c \
				pf_args.c \
				pf_numbers.c \
				pf_chars.c \
				pf_atoi.c
SRC			=	$(addprefix $(SRCDIR), $(SRCNAME))

OBJDIR			=	objs/
OBJ			=	$(SRC:$(SRCDIR)%.c=$(OBJDIR)%.o)
	
CC			=	gcc	
CFLAGS			=	-Wall -Wextra -Werror
XFLAGS			=

all			:	$(NAME)

$(NAME)			:	$(OBJDIR) $(OBJ)
	make -C libft/			 
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)
		   
$(OBJDIR)		:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o		:	$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $^

clean			:	
	rm -rf $(OBJ)
	rm -rf $(OBJDIR)
	make clean -C libft/ 

fclean			:	clean
	rm -rf $(NAME)
	make fclean -C libft/ 

re			:	fclean all

.PHONY			:	all clean fclean re
