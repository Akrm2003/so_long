/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asid-ahm <asid-ahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 03:15:43 by asid-ahm          #+#    #+#             */
/*   Updated: 2024/08/11 16:52:03 by asid-ahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(t_map *map, char *str)
{
	ft_free(NULL, map->map);
	ft_putstr_fd(str, 2);
	exit(1);
}

int	ft_quit(t_map *map)
{
	mlx_destroy_window(map->mlx, map->mlx_win);
	ft_free(NULL, map->map);
	exit(0);
}

void	ft_free(void *one_p, char **two_p)
{
	int	i;

	i = -1;
	if (one_p)
	{
		free(one_p);
		one_p = NULL;
	}
	if (two_p)
	{
		while (two_p[++i])
			free(two_p[i]);
		free(two_p);
		two_p = NULL;
	}
}
