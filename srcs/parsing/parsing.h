/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:02:31 by bterral           #+#    #+#             */
/*   Updated: 2022/05/18 16:54:18 by bterral          ###   ########.fr       */
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
int		is_rgb_valid(char **split, int *bool, t_rgb *rgb);

#endif