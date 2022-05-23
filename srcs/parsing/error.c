/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:51:51 by bterral           #+#    #+#             */
/*   Updated: 2022/05/23 11:35:36 by bterral          ###   ########.fr       */
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
	else if (code == 8)
		ft_dprintf(2, "First or last line are not full of walls\n", str);
	else if (code == 9)
		ft_dprintf(2, "Map must be surrounded by walls\n", str);
	else if (code == 10)
		ft_dprintf(2, "One and only one player must be placed on the map\n", str);
	return (1);
}
