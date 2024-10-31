/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asid-ahm <asid-ahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:19:40 by asid-ahm          #+#    #+#             */
/*   Updated: 2024/08/11 17:07:42 by asid-ahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/fcntl.h>
# include <sys/wait.h>
# include "libft/SRC/libft.h"
# include "mlx/mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_map
{
	char	**map;
	int		steps;
	void	*mlx;
	void	*mlx_win;
	void	*wall;
	void	*floor;
	void	*player;
	void	*exit;
	void	*collectible;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		gate_x;
	int		gate_y;
	int		players_num;
	int		coins;
	int		gates_num;
}	t_map;

void	print_error(int error);
int		check_if_rectangular(t_map *map);
int		check_number_of_elem(t_map *map);
size_t	gnl_ft_strlen(char *str);
char	*gnl_ft_strchr(const char *s, int c);
char	*gnl_ft_strjoin(char *s1, char *s2);
char	*gnl_ft_strdup(char *s1);
char	*get_next_line(int fd);
void	ft_free(void *one_p, char **two_p);
void	read_the_map(int fd, t_map *map, char **av);
void	init_map(t_map *map);
int		map_open(char *file);
void	print_map(t_map map);
void	check_valid_path(t_map map);
int		ft_move(int keycode, t_map *map);
int		ft_quit(t_map *map);
void	invalid_element(t_map *map);
void	error(t_map *map, char *str);
void	init_positions(t_map *map, int i, int j);
void	recursive_valid_path(t_map *valid_map, int x, int y);
#endif