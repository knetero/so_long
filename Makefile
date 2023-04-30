# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/30 14:22:15 by abazerou          #+#    #+#              #
#    Updated: 2023/04/30 18:49:02 by abazerou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
FLAG = -Wall -Wextra -Werror
flg_mlx = -lmlx -framework OpenGL -framework AppKit 
CC = cc 
RM = rm -f 

SRC = so_long.c get_next_line.c get_next_line_utils.c \
 	utils.c m_parcing.c m_graphics.c valid_path.c \
	keys_helpers.c keys.c

OBJ = $(SRC:.c=.o)

all: $(NAME)


$(NAME): $(OBJ)
	$(CC) $(FLAG) $(OBJ) $(flg_mlx) -o $(NAME)

%.o: %.c so_long.h
	$(CC) $(FLAG)  -Imlx -c $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all