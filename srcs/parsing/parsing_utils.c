/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:38:44 by bterral           #+#    #+#             */
/*   Updated: 2022/05/17 16:27:11 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	initialize_texture(t_map *map)
{
	map->no_file = NULL;
	map->so_file = NULL;
	map->we_file = NULL;
	map->ea_file = NULL;
	map->map = NULL;
	map->c_bool = 0;
	map->ceiling->red = 0;
	map->ceiling->green = 0;
	map->ceiling->blue = 0;
	map->f_bool = 0;
	map->floor->red = 0;
	map->floor->green = 0;
	map->floor->blue = 0;
}

int	before_map(char *line)
{
	int map_starts_here;
	
	
}