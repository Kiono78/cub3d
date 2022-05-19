/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 09:59:55 by bterral           #+#    #+#             */
/*   Updated: 2022/05/19 11:11:27 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	rgb_atoi_value(char *str, int start, int len, int *boolean)
{
	char	*truncated_str;
	int		rgb_code;
	int		i;

	truncated_str = ft_substr(str, start, len);
	i = 0;
	while (truncated_str[i])
	{
		if (!ft_isdigit(truncated_str[i]))
		{
			*boolean = 2;
			return (print_error(6, truncated_str));
		}
		i++;
	}
	rgb_code = ft_atoi(truncated_str);
	if (rgb_code < 0 || rgb_code > 255)
	{
		*boolean = 2;
		return (print_error(7, truncated_str));
	}
	return (rgb_code);
}

int	rgb_value_check(char *str, int *boolean, t_rgb *rgb)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == ',')
		{
			if (!rgb->red)
				rgb->red = rgb_atoi_value(str, j, i - j, boolean);
			else if (!rgb->green)
				rgb->green = rgb_atoi_value(str, j, i - j, boolean);
			else if (!rgb->green)
				rgb->blue = rgb_atoi_value(str, j, i - j, boolean);
			if (*boolean == 2)
				return (1);
			j = (i + 1);
		}
		i++;
	}
	*boolean = 1;
	return (0);
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
		return (print_error(5, str));
	return (rgb_value_check(str, boolean, rgb));
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
	return (rgb_comma_check(concat, boolean, rgb));
}
