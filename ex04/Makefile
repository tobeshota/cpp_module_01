# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: toshota <toshota@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/03 16:13:09 by toshota           #+#    #+#              #
#    Updated: 2024/06/07 18:58:46 by toshota          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_sed
CC			=	c++
FLAGS		=	-Wall -Wextra -Werror -std=c++98 -pedantic-errors
RM			=	rm -rf
OBJS_DIR	=	objs/

SRCS		=	$(wildcard *.cpp)
OBJS		=	$(patsubst %.cpp, $(OBJS_DIR)%.o, $(SRCS))

ifeq ($(MAKECMDGOALS), debug)
	FLAGS += -DDEBUG
endif

ifeq ($(MAKECMDGOALS), address)
	CFLAGS += -g3 -fsanitize=address
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $@

$(OBJS_DIR)%.o : %.cpp
	mkdir -p $(@D)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_DIR)

fclean:
	$(RM) $(OBJS_DIR) $(NAME)

re:		fclean all

debug: re

address: re

.PHONY:	all clean fclean re debug address
