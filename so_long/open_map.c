/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asid-ahm <asid-ahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 02:40:49 by asid-ahm          #+#    #+#             */
/*   Updated: 2024/08/11 16:30:38 by asid-ahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	map_name_check(char *file)
{
	int		size;
	int		n;
	char	*map_name;

	n = 3;
	map_name = ".ber";
	if (!file)
	{
		ft_putstr_fd("Error\nMap file not found.\n", 2);
		exit(1);
	}
	size = ft_strlen(file) - 1;
	while (size >= 0 && n > -1)
	{
		if (file[size] == map_name[n])
			n--;
		else
			return (0);
		size--;
	}
	if (n == -1)
		return (1);
	return (0);
}

int	map_open(char *file)
{
	int	fd;

	if (!map_name_check(file))
	{
		ft_putstr_fd("Error\nMap name is wrong.\n", 2);
		exit(1);
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nMap file not found.\n", 2);
		exit(1);
	}
	return (fd);
}
