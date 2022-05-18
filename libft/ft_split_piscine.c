/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_piscine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:38:59 by bterral           #+#    #+#             */
/*   Updated: 2022/05/18 11:38:43 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_charset(char c, char *charset);
static size_t	get_size(const char *s, char *c);
static size_t	get_len(const char *str, char *c);
static char		**get_strings(char const *s, char *c, size_t split_size);
static char		**ft_clean_malloc(char **output);

static int	is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	get_size(const char *s, char *c)
{
	size_t	count;
	char	boolean;

	count = 0;
	boolean = 0;
	while (*s)
	{
		if (!is_charset(*s, c))
			boolean = 1;
		else if (is_charset(*s, c) && boolean == 1)
		{
			count++;
			boolean = 0;
		}
		s++;
	}
	if (boolean == 1)
		count++;
	return (count);
}

static size_t	get_len(const char *str, char *c)
{
	size_t	count;

	count = 0;
	while (!is_charset(*str, c) && *str)
	{
		count++;
		str++;
	}
	return (count);
}

static char	**ft_clean_malloc(char **output)
{
	size_t	i;

	i = 0;
	while (output[i++])
		free(output[i]);
	free(output);
	return (NULL);
}

static char	**get_strings(char const *s, char *c, size_t split_size)
{
	char	**str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	str = (char **)malloc(sizeof(s) * (split_size + 1));
	if (!str)
		return (NULL);
	while (split_size-- > 0)
	{
		while (is_charset(s[i], c))
			i++;
		if (!is_charset(s[i], c))
		{
			str[j] = ft_substr(s, i, get_len(&s[i], c));
			if (str[j] == NULL)
				return (ft_clean_malloc(str));
			i += get_len(&s[i], c);
			j++;
		}
	}
	str[j] = 0;
	return (str);
}

char	**ft_split_piscine(char const *s, char *c)
{
	char			**output;
	size_t			split_size;

	if (!s)
		return (NULL);
	split_size = get_size(s, c);
	output = get_strings(s, c, split_size);
	return (output);
}
