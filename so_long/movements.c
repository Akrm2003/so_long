/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asid-ahm <asid-ahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:39:29 by asid-ahm          #+#    #+#             */
/*   Updated: 2024/08/11 16:30:18 by asid-ahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_up(t_map *map)
{
	if (map->map[map->player_y - 1][map->player_x] != '1')
	{
		if (map->map[map->player_y - 1][map->player_x] == 'E')
		{
			if (map->coins != 0)
				ft_putstr_fd("Collect all coins before exiting.\n", 2);
			else if (map->coins == 0)
				ft_quit(map);
		}
		else
		{
			ft_putstr_fd("your steps: ", 1);
			map->steps++;
			ft_putnbr_fd(map->steps, 1);
			ft_putchar_fd('\n', 1);
			map->map[map->player_y][map->player_x] = '0';
			map->player_y--;
			map->map[map->player_y][map->player_x] = 'P';
		}
	}
}

static void	ft_down(t_map *map)
{
	if (map->map[map->player_y + 1][map->player_x] != '1')
	{
		if (map->map[map->player_y + 1][map->player_x] == 'E')
		{
			if (map->coins != 0)
				ft_putstr_fd("Collect all coins before exiting.\n", 2);
			else if (map->coins == 0)
				ft_quit(map);
		}
		else
		{
			ft_putstr_fd("your steps: ", 1);
			map->steps++;
			ft_putnbr_fd(map->steps, 1);
			ft_putchar_fd('\n', 1);
			map->map[map->player_y][map->player_x] = '0';
			map->player_y++;
			map->map[map->player_y][map->player_x] = 'P';
		}
	}
}

static void	ft_left(t_map *map)
{
	if (map->map[map->player_y][map->player_x - 1] != '1')
	{
		if (map->map[map->player_y][map->player_x - 1] == 'E')
		{
			if (map->coins != 0)
				ft_putstr_fd("Collect all coins before exiting.\n", 2);
			else if (map->coins == 0)
				ft_quit(map);
		}
		else
		{
			ft_putstr_fd("your steps: ", 1);
			map->steps++;
			ft_putnbr_fd(map->steps, 1);
			ft_putchar_fd('\n', 1);
			map->map[map->player_y][map->player_x] = '0';
			map->player_x--;
			map->map[map->player_y][map->player_x] = 'P';
		}
	}
}

static void	ft_right(t_map *map)
{
	if (map->map[map->player_y][map->player_x + 1] != '1')
	{
		if (map->map[map->player_y][map->player_x + 1] == 'E')
		{
			if (map->coins != 0)
				ft_putstr_fd("Collect all coins before exiting.\n", 2);
			else if (map->coins == 0)
				ft_quit(map);
		}
		else
		{
			ft_putstr_fd("your steps: ", 1);
			map->steps++;
			ft_putnbr_fd(map->steps, 1);
			ft_putchar_fd('\n', 1);
			map->map[map->player_y][map->player_x] = '0';
			map->player_x++;
			map->map[map->player_y][map->player_x] = 'P';
		}
	}
}

int	ft_move(int keycode, t_map *map)
{
	if (keycode == 53)
	{
		mlx_destroy_window(map->mlx, map->mlx_win);
		ft_free(NULL, map->map);
		exit(0);
	}
	if (keycode == 13)
		ft_up(map);
	else if (keycode == 1)
		ft_down(map);
	else if (keycode == 0)
		ft_left(map);
	else if (keycode == 2)
		ft_right(map);
	return (0);
}
