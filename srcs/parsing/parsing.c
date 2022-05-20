/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:59:12 by bterral           #+#    #+#             */
/*   Updated: 2022/05/20 11:07:46 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int read_texture(int fd, t_map *map)
{
	char	**split;

	initialize_texture(map);
	split = split_spaces(get_next_line(fd));
	while (split && are_info_missing(map))
	{
		if (split[0])
		{
			if (is_valid_identifier(split[0]))
				return (print_error(3, split[0]));
			if (is_valid_value(split, map))
				return (1);
		}
		free(split);
		split = split_spaces(get_next_line(fd));
	}
	if (split)
		free(split);
	return (parse_map(fd, map));
}

int parsing(int argc, char **argv, t_map *map)
{
	int	map_len;
	int	file_fd;

	if (argc != 2)
		return (print_error(0, NULL));
	map_len = ft_strlen(argv[1]);
	if ((map_len < 4) || ft_strncmp(&argv[1][map_len - 4], ".cub", 4))
		return (print_error(1, argv[1]));
	file_fd = open(argv[1], O_RDONLY);
	if (file_fd == -1)
		return (print_error(2, argv[1]));
	else
		return (read_texture(file_fd, map));
	return (0);
}
