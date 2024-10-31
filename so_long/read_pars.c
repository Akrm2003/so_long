/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_pars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asid-ahm <asid-ahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:48:07 by asid-ahm          #+#    #+#             */
/*   Updated: 2024/08/11 17:13:02 by asid-ahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(int error)
{
	if (error == 1)
		ft_putstr_fd("Error\nInvalid element in the map\n", 2);
	else if (error == 2)
		ft_putstr_fd("Error\nInvalid number of players\n", 2);
	else if (error == 3)
		ft_putstr_fd("Error\nNo coins in the map\n", 2);
	else if (error == 4)
		ft_putstr_fd("Error\nNo gate in the map\n", 2);
}

int	check_if_rectangular(t_map *map)
{
	size_t	len;
	int		j;

	len = ft_strlen(map->map[0]);
	j = -1;
	while (map->map[++j])
	{
		if (ft_strlen(map->map[j]) != len)
		{
			ft_putstr_fd("Error\nMap is not rectangular\n", 2);
			ft_free(NULL, map->map);
			exit(1);
		}
	}
	return (0);
}

int	check_number_of_elem(t_map *map)
{
	if (map->players_num != 1)
		return (2);
	if (map->coins < 1)
		return (3);
	if (map->gates_num != 1)
		return (4);
	return (0);
}

void	invalid_element(t_map *map)
{
	int	j;
	int	i;

	j = -1;
	while (map->map[++j])
	{
		i = -1;
		while (map->map[j][++i])
		{
			if (map->map[j][i] == 'P')
				map->players_num++;
			else if (map->map[j][i] == 'C')
				map->coins++;
			else if (map->map[j][i] == 'E')
				map->gates_num++;
			else if (map->map[j][i] != '1' && map->map[j][i] != '0')
				(ft_putstr_fd("Error\n Invalid Character\n", 2), exit(1));
			init_positions(map, i, j);
		}
	}
	i = check_number_of_elem(map);
	if (i)
		(print_error(i), ft_free(NULL, map->map), exit(1));
}
