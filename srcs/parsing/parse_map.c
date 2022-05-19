/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 13:38:48 by bterral           #+#    #+#             */
/*   Updated: 2022/05/19 16:53:12 by bterral          ###   ########.fr       */
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

// int	parse_map(int fd, t_map *map)
// {
// 	char	**line;
// 	int		i;

// 	i = 0;
// 	line = ft_split(get_next_line(fd), '\n');
// 	if (check_full_walls(line[0]))
// 	{
// 		free(line);
// 		return (print_error(9, NULL));
// 	}
// 	while (line[0] && line[0][0] != '\n')
// 	{
// 		i++;
// 		line = ft_split(get_next_line(fd), '\n');
// 	}
// 	return (0);
// }

int	map_size(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
		i++;
	return (i);
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
	return (0);
}