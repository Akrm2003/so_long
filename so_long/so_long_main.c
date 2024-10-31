/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asid-ahm <asid-ahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:19:33 by asid-ahm          #+#    #+#             */
/*   Updated: 2024/08/11 16:51:52 by asid-ahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_mlx(t_map *map)
{
	int	size;

	size = 60;
	map->mlx = mlx_init();
	if (!map->mlx)
		error(map, "Mlx Failed.\n");
	map->wall = mlx_xpm_file_to_image(map->mlx, "texture/wall.xpm", &size,
			&size);
	map->floor = mlx_xpm_file_to_image(map->mlx, "texture/floor.xpm", &size,
			&size);
	map->player = mlx_xpm_file_to_image(map->mlx, "texture/asta_r.xpm", &size,
			&size);
	map->exit = mlx_xpm_file_to_image(map->mlx, "texture/closed_door.xpm",
			&size, &size);
	map->collectible = mlx_xpm_file_to_image(map->mlx,
			"texture/collectable.xpm", &size, &size);
	if (!map->wall || !map->floor || !map->player || !map->exit)
		error(map, "Failed To Upload Images.\n");
	map->mlx_win = mlx_new_window(map->mlx, map->width * 60, map->height * 60,
			"so_long");
	if (!map->mlx_win)
		error(map, "Failed To Create Window.\n");
}

void	update_coins(t_map *map)
{
	int	j;
	int	i;

	j = -1;
	map->coins = 0;
	while (map->map[++j])
	{
		i = -1;
		while (map->map[j][++i])
		{
			if (map->map[j][i] == 'C')
				map->coins++;
		}
	}
}

void	put_image(t_map *map, int i, int j)
{
	if (map->map[i][j] == '1')
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->wall, j
			* 60, i * 60);
	else if (map->map[i][j] == 'P')
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->player, j
			* 60, i * 60);
	else if (map->map[i][j] == 'E')
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->exit, j
			* 60, i * 60);
	else if (map->map[i][j] == 'C')
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->collectible, j * 60, i * 60);
}

int	render_map(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	mlx_clear_window(map->mlx, map->mlx_win);
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			mlx_put_image_to_window(map->mlx, map->mlx_win, map->floor, j * 60,
				i * 60);
			put_image(map, i, j);
		}
	}
	update_coins(map);
	return (0);
}

int	main(int ac, char **av)
{
	int		fd;
	t_map	map;

	if (ac != 2)
		(ft_putstr_fd("Error\nInvalid number of arguments\n", 2), exit(1));
	fd = map_open(av[1]);
	init_map(&map);
	read_the_map(fd, &map, av);
	close(fd);
	check_valid_path(map);
	init_mlx(&map);
	render_map(&map);
	mlx_loop_hook(map.mlx, render_map, &map);
	mlx_hook(map.mlx_win, 2, 0, ft_move, &map);
	mlx_hook(map.mlx_win, 17, 0, ft_quit, &map);
	mlx_loop(map.mlx);
	return (0);
}
