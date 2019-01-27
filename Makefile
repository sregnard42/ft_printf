# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sregnard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 14:51:18 by sregnard          #+#    #+#              #
#    Updated: 2019/01/27 17:59:26 by sregnard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libftprintf.a

LIBFTDIR		=	libft/
LIBFT			=	$(LIBFTDIR)libft.a

HEADDIR			=	includes/
HEADERS			=	-I $(HEADDIR)
HEADERS			+=	-I $(LIBFTDIR)$(HEADDIR)

SRCDIR			=	srcs/
SRCNAME			= 	ft_printf.c
SRC				=	$(addprefix $(SRCDIR), $(SRCNAME))

OBJDIR			=	objs/
OBJ				=	$(SRC:$(SRCDIR)%.c=$(OBJDIR)%.o)
	
CC				=	gcc	
CFLAGS			=	-Wall -Wextra -Werror
XFLAGS			=	-g3

all				:	$(NAME)

$(NAME)			:	$(LIBFT) $(OBJDIR) $(OBJ)
	ar rcsu $@ $(OBJ) $(LIBFT)

$(LIBFT)		:
	$(MAKE) -C $(LIBFTDIR)
	rm -rf $(NAME)
	cp $(LIBFT) $(NAME)
	  
$(OBJDIR)		:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o	:	$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $^

clean			:	
	rm -rf $(OBJDIR)
	$(MAKE) clean -C $(LIBFTDIR)

fclean			:	clean
	rm -rf $(NAME)
	rm -rf $(LIBFT)

re				:	fclean all

cleanfpf		:
	rm -rf $(OBJDIR)

fcleanfpf		:	cleanfpf
	rm -rf $(NAME)

refpf			:	fcleanfpf all

.PHONY			:	all clean fclean re cleanfpf fcleanfpf refpf
