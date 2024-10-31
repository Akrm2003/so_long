/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_the_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asid-ahm <asid-ahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 16:31:32 by asid-ahm          #+#    #+#             */
/*   Updated: 2024/08/11 17:13:46 by asid-ahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	map_size(int fd)
{
	char	*line;
	int		size;

	size = 0;
	line = get_next_line(fd);
	while (line)
	{
		size++;
		if (ft_strlen(line) > 53 || size > 29)
		{
			free(line);
			ft_putstr_fd("Error\nMap is too big\n", 2);
			exit(1);
		}
		free(line);
		line = NULL;
		line = get_next_line(fd);
	}
	return (size);
}

void	init_positions(t_map *map, int i, int j)
{
	if (map->map[j][i] == 'P')
	{
		map->player_x = i;
		map->player_y = j;
	}
	else if (map->map[j][i] == 'E')
	{
		map->gate_x = i;
		map->gate_y = j;
	}
}

void	init_map(t_map *map)
{
	map->players_num = 0;
	map->map = NULL;
	map->height = 0;
	map->width = 0;
	map->player_x = 0;
	map->player_y = 0;
	map->coins = 0;
	map->gate_x = 0;
	map->gate_y = 0;
	map->gates_num = 0;
	map->steps = 0;
}

void	surrounded_by_walls(t_map *map)
{
	int	i;
	int	j;

	j = -1;
	while (map->map[++j])
	{
		i = -1;
		while (map->map[j][++i])
		{
			if (i == 0 || j == 0 || i == map->width - 1 || j == map->height - 1)
			{
				if (map->map[j][i] != '1')
				{
					ft_putstr_fd("Error\nMap is not surrounded by walls\n", 2);
					ft_free(NULL, map->map);
					exit(1);
				}
			}
		}
	}
}

void	read_the_map(int fd, t_map *map, char **av)
{
	char	*line;
	int		i;

	map->height = map_size(fd);
	close(fd);
	map->map = malloc(sizeof(char *) * (map->height + 1));
	i = 0;
	fd = map_open(av[1]);
	line = ft_strtrim(get_next_line(fd), "\n");
	while (line)
	{
		map->map[i++] = line;
		line = ft_strtrim(get_next_line(fd), "\n");
	}
	map->map[i] = NULL;
	if (!map->map || !map->map[0])
	{
		ft_putstr_fd("Error\nMap is empty\n", 2);
		if (map->map)
			(ft_free(NULL, map->map), exit(1));
	}
	map->width = ft_strlen(map->map[0]);
	invalid_element(map);
	(check_if_rectangular(map), surrounded_by_walls(map));
}
