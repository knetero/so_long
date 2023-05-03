# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/30 14:22:15 by abazerou          #+#    #+#              #
#    Updated: 2023/05/03 11:31:00 by abazerou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
FLAG = -Wall -Wextra -Werror -g3
flg_mlx = -lmlx -framework OpenGL -framework AppKit 
CC = cc 
RM = rm -f 

SRC = so_long.c get_next_line.c get_next_line_utils.c \
 	utils.c m_parcing.c m_graphics.c valid_path.c \
	keys_helpers.c keys.c

red			=	`tput setaf 1`
green		=	`   tput setaf 2`

OBJ = $(SRC:.c=.o)

all: $(NAME)


$(NAME): $(OBJ)
	$(CC) $(FLAG) $(OBJ) $(flg_mlx) -o $(NAME)
	@echo " [$(green)SUCCESS$(white)] so_long $(green)is ready$(white)."

%.o: %.c so_long.h
	$(CC) $(FLAG)  -Imlx -c $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	@echo " [$(green)OBJ & EXEC$(white)] so_long $(green)removed$(white)."

re: fclean all