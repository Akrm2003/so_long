# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asid-ahm <asid-ahm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/11 14:09:49 by asid-ahm          #+#    #+#              #
#    Updated: 2024/08/11 15:50:58 by asid-ahm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
AR = ar -rcs
RM = rm -f

FILES = ft_free get_next_line_utils get_next_line so_long_main open_map read_the_map valid_path movements read_pars

LIBFT = libft/libft.a
MLX = mlx/libmlx.a

SRCS = $(addsuffix .c, $(FILES))

OBJS = $(addsuffix .o, $(FILES))

all: $(NAME)

$(LIBFT):
	make -C libft
$(MLX):
	make -C mlx

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -g3 -c $< -o $@

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -framework OpenGL -framework AppKit -o $(NAME)

clean:
	make clean -C libft
	make clean -C mlx
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(MLX) $(LIBFT)

re: clean all

.PHONY: bonus all clean fclean re