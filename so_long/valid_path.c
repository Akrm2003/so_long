/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asid-ahm <asid-ahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 08:55:49 by asid-ahm          #+#    #+#             */
/*   Updated: 2024/08/11 17:08:37 by asid-ahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_map	dup_map(t_map map)
{
	t_map	new_map;
	int		i;

	i = -1;
	new_map.map = (char **)malloc(sizeof(char *) * (map.height + 1));
	if (!new_map.map)
		return (new_map);
	while (map.map[++i])
		new_map.map[i] = ft_strdup(map.map[i]);
	new_map.map[i] = NULL;
	new_map.height = map.height;
	new_map.player_x = map.player_x;
	new_map.player_y = map.player_y;
	new_map.coins = map.coins;
	new_map.gate_x = map.gate_x;
	new_map.gate_y = map.gate_y;
	return (new_map);
}

void	ft_maaref(t_map *valid_map, int x, int y)
{
	if (valid_map->map[y][x + 1] == '0' || valid_map->map[y][x + 1] == 'C')
	{
		if (valid_map->map[y][x + 1] == 'C')
			valid_map->coins--;
		valid_map->map[y][x + 1] = 'K';
		recursive_valid_path(valid_map, x + 1, y);
	}
	if (valid_map->map[y][x - 1] == '0' || valid_map->map[y][x - 1] == 'C')
	{
		if (valid_map->map[y][x - 1] == 'C')
			valid_map->coins--;
		valid_map->map[y][x - 1] = 'K';
		recursive_valid_path(valid_map, x - 1, y);
	}
}

void	recursive_valid_path(t_map *valid_map, int x, int y)
{
	ft_maaref(valid_map, x, y);
	if (valid_map->map[y + 1][x] == '0' || valid_map->map[y + 1][x] == 'C')
	{
		if (valid_map->map[y + 1][x] == 'C')
			valid_map->coins--;
		valid_map->map[y + 1][x] = 'K';
		recursive_valid_path(valid_map, x, y + 1);
	}
	if (valid_map->map[y - 1][x] == '0' || valid_map->map[y - 1][x] == 'C')
	{
		if (valid_map->map[y - 1][x] == 'C')
			valid_map->coins--;
		valid_map->map[y - 1][x] = 'K';
		recursive_valid_path(valid_map, x, y - 1);
	}
}

static int	check_exit(t_map valid_map)
{
	if (valid_map.map[valid_map.gate_y][valid_map.gate_x + 1] == 'K'
		|| valid_map.map[valid_map.gate_y][valid_map.gate_x - 1] == 'K'
		|| valid_map.map[valid_map.gate_y + 1][valid_map.gate_x] == 'K'
		|| valid_map.map[valid_map.gate_y - 1][valid_map.gate_x] == 'K')
		return (0);
	if (valid_map.map[valid_map.gate_y][valid_map.gate_x + 1] == 'P'
		|| valid_map.map[valid_map.gate_y][valid_map.gate_x - 1] == 'P'
		|| valid_map.map[valid_map.gate_y + 1][valid_map.gate_x] == 'P'
		|| valid_map.map[valid_map.gate_y - 1][valid_map.gate_x] == 'P')
		return (0);
	return (1);
}

void	check_valid_path(t_map map)
{
	t_map	valid_map;

	valid_map = dup_map(map);
	recursive_valid_path(&valid_map, map.player_x, map.player_y);
	if (valid_map.coins != 0)
	{
		ft_putstr_fd("Error\nInvalid Path for coins\n", 2);
		ft_free(NULL, valid_map.map);
		ft_free(NULL, map.map);
		exit(1);
	}
	if (check_exit(valid_map))
	{
		ft_putstr_fd("Error\nInvalid Path\n", 2);
		ft_free(NULL, map.map);
		ft_free(NULL, valid_map.map);
		exit(1);
	}
	ft_free(NULL, valid_map.map);
}
