/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:59:12 by bterral           #+#    #+#             */
/*   Updated: 2022/05/19 11:25:35 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	print_error(int code, char *str)
{
	(void)str;
	ft_dprintf(2, "Error\n");
	if (code == 0)
		ft_dprintf(2, "A single argument required: The map file\n");
	else if (code == 1)
		ft_dprintf(2, "%s does not have the required .cub extension\n", str);
	else if (code == 2)
		perror(str);
	else if (code == 3)
		ft_dprintf(2, "%s: bad texture code\n", str);
	else if (code == 4)
		ft_dprintf(2, "%s: bad texture value\n", str);
	else if (code == 5)
		ft_dprintf(2, "%s: not a valid rgb format, two comma.\n", str);
	else if (code == 6)
		ft_dprintf(2, "%s: not a valid rgb format, digits.\n", str);
	else if (code == 7)
		ft_dprintf(2, "%s: not a valid rgb format, value.\n", str);
	return (1);
}

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
				// return (print_error(4, split[1]));
				return (1);
		}
		free(split);
		split = split_spaces(get_next_line(fd));
	}
	if (split)
		free(split);
	return (0);
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
