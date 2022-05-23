/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 13:38:48 by bterral           #+#    #+#             */
/*   Updated: 2022/05/23 11:29:07 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_full_walls(char *line)
{
	while(*line)
	{
		if (*line != '1' && *line != ' ')
			return (1);
		line++;
	}
	return (0);
}

char	*add_line_to_map(char *line, char *map)
{
	char *tmp;

	if (!map)
		map = ft_strdup(line);
	else
	{
		tmp = ft_strjoin(map, line);
		free(map);
		map = tmp;
	}
	return (map);
}

int	map_size(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
		i++;
	return (i);
}

int check_map_closed(t_map *map, int x, int y)
{
	if (check_left(map, x, y))
	{
		printf("checking left x: %d - y: %d\n", x, y);
		return (1);
	}
	if (check_right(map, x, y))
	{
		printf("checking right x: %d - y: %d\n", x, y);
		return (1);
	}
	if (check_up(map, x, y))
	{
		printf("checking up x: %d - y: %d\n", x, y);
		return (1);
	}
	if (check_down(map, x, y))
	{
		printf("checking down x: %d - y: %d\n", x, y);
		return (1);
	}
	return (0);
}

int	check_map_consistency(t_map *map)
{
	int	i;
	int	j;
	int	player;

	j = 0;
	player = 0;
	while (j < map->y)
	{
		i = 0;
		while ((map->map[j][i]))
		{
			if (map->map[j][i] != '1' && map->map[j][i] != ' ')
			{
				if (map->map[j][i] == 'N' || map->map[j][i] == 'S' ||
					map->map[j][i] == 'W' || map->map[j][i] == 'E')
					player++;					
				if (check_map_closed(map, i, j))
					return (print_error(9, NULL));
			}
			i++;
		}
		j++;
	}
	if (player != 1)
		return (print_error(10, NULL));
	return (0);
}

int	parse_map(int fd, t_map *map)
{
	char	*internediary_map;
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		internediary_map = add_line_to_map(line, internediary_map);
		free(line);
		line = get_next_line(fd);
	}
	map->map = ft_split(internediary_map, '\n');
	map->y = map_size(map);
	if (check_full_walls(map->map[0]) || check_full_walls(map->map[map->y - 1]))
		return (print_error(8, NULL));
	if (check_map_consistency(map))
		return (1);
	return (0);
}
