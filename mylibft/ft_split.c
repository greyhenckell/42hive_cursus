/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenckel <fhenckel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 09:47:53 by fhenckel          #+#    #+#             */
/*   Updated: 2024/11/08 09:47:58 by fhenckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	count_items(char const *str, char delim)
{
	int	cntword;
	int	flag;

	cntword = 0;
	flag = 0;
	while (*str != '\0')
	{
		if (*str != delim && flag == 0)
		{
			flag = 1;
			cntword++;
		}
		else if (*str == delim)
			flag = 0;
		str++;
	}
	return (cntword);
}

static void	check_allocation(char **out, int size, int idx)
{
	out[idx] = (char *)malloc((size + 1) * sizeof(char));
	if (out[idx] == NULL)
	{
		while (idx-- >= 0)
			free(out[idx]);
		free(out);
	}
}

static void	allocate_items(char **out, char const *s, char c)
{
	int	start;
	int	end;
	int	idx;

	start = 0;
	end = 0;
	idx = 0;
	while (s[start] != '\0')
	{
		while (s[start] == c)
			start++;
		end = start;
		while (s[end] != c && s[end] != '\0')
			end++;
		if (end > start)
		{
			check_allocation(out, end - start, idx);
			if (!out)
				return ;
			ft_strlcpy(out[idx], s + start, end - start + 1);
			idx++;
		}
		start = end;
	}
	out[idx] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**out;
	int		array_size;

	out = NULL;
	if (c == '\0' && s)
		array_size = 1;
	else
		array_size = count_items(s, c);
	out = (char **)malloc((array_size + 1) * sizeof(char *));
	if (out == NULL)
		return (NULL);
	allocate_items(out, s, c);
	if (!out)
		return (NULL);
	return (out);
}
