/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_consistency.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:07:32 by bterral           #+#    #+#             */
/*   Updated: 2022/05/23 11:35:57 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_left(t_map *map, int x, int y)
{
	int i;

	i = 1;
	while ((x - i) >= 0 && map->map[y][x - i] && map->map[y][x - i] != ' ')
	{
		if (map->map[y][x - i] == '1')
			return (0);
		i++;
	}
	printf("Left Error x: %d, y: %d, value: %c\n", (x - i), y, map->map[y][x + i]);
	return (1);
}

int	check_right(t_map *map, int x, int y)
{
	int i;

	i = 1;
	while (map->map[y][x + i] && map->map[y][x + i] != ' ')
	{
		if (map->map[y][x + i] == '1')
			return (0);
		i++;
	}
	return (1);
	printf("Right Error x: %d, y: %d, value: %c\n", (x + i), y, map->map[y][x + i]);
}

int	check_up(t_map *map, int x, int y)
{
	int i;

	i = 1;
	while ((y - i) >= 0 && map->map[y - i][x] && map->map[y - i][x] != ' ')
	{
		if (map->map[y - i][x] == '1')
			return (0);
		i++;
	}
	printf("Up Error x: %d, y: %d, value: %c\n", x, (y - i), map->map[y - i][x]);
	return (1);
}

int	check_down(t_map *map, int x, int y)
{
	int i;

	i = 1;
	while ((y + i) < map->y && map->map[y + i][x] && map->map[y + i][x] != ' ')
	{
		if (map->map[y + i][x] == '1')
			return (0);
		i++;
	}
	printf("Down Error x: %d, y: %d, value: %c\n", x, (y + i), map->map[y + i][x]);
	return (1);
}