/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:59:12 by bterral           #+#    #+#             */
/*   Updated: 2022/05/17 16:24:35 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	print_error(void)
{
	ft_dprintf(2, "Error\n");
	return (1);
}

int read_texture(int fd, t_map *map)
{
	char *line;

	line = get_next_line(fd);
	initialize_texture(map);
	while (before_map(line))
	//  && ((!map->no_file) || (!map->so_file) || (!map->we_file)
	// 	|| (!map->ea_file) || (!map->c_bool) || (!map->f_bool)))
	{

	}
}

int parsing(int argc, char **argv, t_map *map)
{
	int	map_len;
	int	file_fd;

	if (argc != 2)
		return (print_error());
	map_len = ft_strlen(argv[1]);
	if ((map_len < 4) || ft_strncmp(&argv[1][map_len - 4], ".cub", 4))
		return (print_error());
	file_fd = open(argv[1], O_RDONLY);
	if (file_fd == -1)
		return (print_error());
	else
		return (read_texture(file_fd, map));
	return (0);
}