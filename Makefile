# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehouot <ehouot@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 10:39:55 by ehouot            #+#    #+#              #
#    Updated: 2023/05/03 19:00:11 by ehouot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC 		= 	parse_swap.c \
				main.c \
				ft_isdigit.c \
				ft_lstnew.c \
				ft_lstsize.c \
				ft_lstsize_mod.c \
				ft_lstadd_back.c \
				ft_atoi.c \
				ft_split.c \
				ft_dispatch.c \
				lst_push.c \
				lst_swap.c \
				lst_rotate.c \
				lst_reverse_rotate.c \
				indexation.c \
				calculation.c \
				ft_algorithm_ps.c \
				algo_utils.c \

OBJ 		= $(SRC:.c=.o)

CC 			= clang

RM 			= rm -f

CFLAGS 		= -Wall -Werror -Wextra

ifdef DEBUG
CFLAGS += -g
endif

NAME 		= push_swap

all:		$(NAME)

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

debug:
	${MAKE} DEBUG=1

clean:
			$(RM) $(OBJ)

fclean: 	clean
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY: 	all clean fclean re