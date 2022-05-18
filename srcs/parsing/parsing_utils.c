/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:38:44 by bterral           #+#    #+#             */
/*   Updated: 2022/05/18 17:54:26 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	initialize_texture(t_map *map)
{
	map->no_file = NULL;
	// map->no_fd = 0;
	map->so_file = NULL;
	// map->so_fd = 0;
	map->we_file = NULL;
	// map->we_fd = 0;
	map->ea_file = NULL;
	// map->ea_fd = 0;
	map->map = NULL;
	map->c_bool = 0;
	map->ceiling.red = 0;
	map->ceiling.green = 0;
	map->ceiling.blue = 0;
	map->f_bool = 0;
	map->floor.red = 0;
	map->floor.green = 0;
	map->floor.blue = 0;
}

int	are_info_missing(t_map *map)
{
	if ((!map->no_file) || (!map->so_file) || (!map->we_file) ||
		(!map->ea_file) || (!map->c_bool) || (!map->f_bool))
		return (1);
	return (0);
}

int	is_valid_identifier(char *str)
{
	if (ft_strcmp(str, "NO") || ft_strcmp(str, "SO") || ft_strcmp(str, "WE") ||
		ft_strcmp(str, "EA") || ft_strcmp(str, "F") || ft_strcmp(str, "C"))
		return (0);
	return (1);
}

int open_file(char *file_name, char **struct_str)
{
	if (open(file_name, O_RDONLY) == -1)
		return (1);
	else
	{
		(*struct_str) = ft_strdup(file_name);
		if (!struct_str)
			return (1);
		return (0);
	}
}

int	rgb_value_check(char *str, int *boolean, t_rgb *rgb)
{
	int i;

	i = 0;
	while (str[i])
	{
		
		i++;
	}
}

int	rgb_comma_check(char *str, int *boolean, t_rgb *rgb)
{
	int	i;
	int	count_comma;

	i = 0;
	count_comma = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count_comma++;
		i++;
	}
	if (count_comma != 2)
		return (1);
	rgb_value_check(str, boolean, rgb);
}

int	is_rgb_valid(char **split, int *boolean, t_rgb *rgb)
{
	char	*concat;
	char	*tmp;
	int		i;

	concat = split[0];
	i = 1;
	while (split[i])
	{
		tmp = ft_strjoin(concat, split[i]);
		free(concat);
		concat = tmp;
		i++;
	}
	rgb_format_check(concat, boolean, rgb);
	return (0);
}

int is_valid_value(char **split, t_map *map)
{
	if (!split[1])
		return (1);
	if (ft_strcmp("NO", split[0]))
		return (open_file(split[1], &(map->no_file)));
	if (ft_strcmp("SO", split[0]))
		return (open_file(split[1], &(map->so_file)));
	if (ft_strcmp("WE", split[0]))
		return (open_file(split[1], &(map->we_file)));
	if (ft_strcmp("EA", split[0]))
		return (open_file(split[1], &(map->ea_file)));
	if (ft_strcmp("F", split[0]))
		return (is_rgb_valid(&split[1], &(map->f_bool), &(map->floor)));
	if (ft_strcmp("C", split[0]))
		return (is_rgb_valid(&split[1], &(map->c_bool), &(map->ceiling)));
	return (1);
}

char	**split_spaces(char *line)
{
	char	**output;

	output = ft_split_piscine(line, " \t\v\f\r\n");
	if (!output)
		return (NULL);
	return (output);
}
