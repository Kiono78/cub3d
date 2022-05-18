/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:34:01 by bterral           #+#    #+#             */
/*   Updated: 2022/05/18 11:13:43 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/cub3d.h"

int main(int argc, char **argv)
{
	t_map	map;

	// map = (t_map *)malloc(sizeof(t_map));
	if (parsing(argc, argv, &map))
		return (1);
	return (0);
}