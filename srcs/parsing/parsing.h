/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:02:31 by bterral           #+#    #+#             */
/*   Updated: 2022/05/20 11:24:32 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <fcntl.h>

# include "../../libft/libft.h"
# include <stdio.h>


typedef	struct s_rgb
{
	int	red;
	int	green;
	int	blue;
}	t_rgb;

typedef struct s_map
{
	char	*no_file;
	char	*so_file;
	char	*we_file;
	char	*ea_file;
	int		c_bool;
	t_rgb	ceiling;
	int		f_bool;
	t_rgb	floor;
	char	**map;
	int		y;
}	t_map;

/// parsing.c ///
int		print_error(int code, char *str);
int 	parsing(int argc, char **argv, t_map *map);
char	**split_spaces(char *line);
void	initialize_texture(t_map *map);
int		read_texture(int fd, t_map *map);
int		is_valid_identifier(char *str);
int		is_valid_value(char **split, t_map *map);
int		open_file(char *file_name, char **struct_str);
int		are_info_missing(t_map *map);


/// rgb_check.c ///
int		is_rgb_valid(char **split, int *boolean, t_rgb *rgb);
int		rgb_comma_check(char *str, int *boolean, t_rgb *rgb);
int		rgb_value_check(char *str, int *boolean, t_rgb *rgb);
int		rgb_atoi_value(char *str, int start, int len, int *boolean);

/// parse_map.c ///
int		parse_map(int fd, t_map *map);

/// map_consistency.c ///
int		check_left(t_map *map, int x, int y);
int		check_right(t_map *map, int x, int y);
int		check_up(t_map *map, int x, int y);
int		check_down(t_map *map, int x, int y);

#endif