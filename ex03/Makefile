# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: toshota <toshota@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/03 16:13:09 by toshota           #+#    #+#              #
#    Updated: 2024/06/07 15:18:38 by toshota          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	a.out
CC			=	c++
FLAGS		=	-Wall -Wextra -Werror -std=c++98 -pedantic-errors
RM			=	rm -rf
INCS		=	-I includes/
SRCS_DIR	=	srcs/
OBJS_DIR	=	objs/

SRCS_FILES	=	HumanA.cpp HumanB.cpp Weapon.cpp main.cpp

SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS		=	$(patsubst $(SRCS_DIR)%.cpp, $(OBJS_DIR)%.o, $(SRCS))


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(INCS) $(OBJS) -o $@

$(OBJS_DIR)%.o : $(SRCS_DIR)%.cpp
	mkdir -p $(@D)
	$(CC) $(FLAGS) $(INCS) -c $< -o $@

clean:
	$(RM) $(OBJS_DIR)

fclean:
	$(RM) $(OBJS_DIR) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
