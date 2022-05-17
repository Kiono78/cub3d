/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:02:31 by bterral           #+#    #+#             */
/*   Updated: 2022/05/17 16:23:17 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <fcntl.h>

# include "../../libft/libft.h"

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
	t_rgb	*ceiling;
	int		f_bool;
	t_rgb	*floor;
	char	*map;
}	t_map;

/// parsing.c ///
int	print_error(void);
int parsing(int argc, char **argv, t_map *map);

#endif