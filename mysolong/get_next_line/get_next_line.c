/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenckel <fhenckel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:16:27 by fhenckel          #+#    #+#             */
/*   Updated: 2024/11/24 14:16:30 by fhenckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	create_line(char **ptrline, int fd, int *bytes_read)
{
	char	*temp;
	char	*buff_content;

	while (*bytes_read > 0 && ft_strchr(*ptrline, '\n') == NULL)
	{
		buff_content = malloc((BUFFER_SIZE + 1));
		if (!buff_content)
			return ;
		*bytes_read = read(fd, buff_content, BUFFER_SIZE);
		if (*bytes_read == -1)
		{
			free(buff_content);
			return ;
		}
		buff_content[*bytes_read] = '\0';
		temp = ft_strjoin(*ptrline, buff_content);
		free(*ptrline);
		free(buff_content);
		if (!temp)
		{
			*ptrline = NULL;
			return ;
		}
		*ptrline = temp;
	}
}

char	*allocate_line(char **headline)
{
	char	*temp;
	char	*out;
	size_t	rem_len;
	char	*ptrline;

	ptrline = ft_strchr(*headline, '\n');
	rem_len = ptrline - *headline + 1;
	out = malloc((rem_len + 1) * sizeof(char));
	if (!out)
		return (NULL);
	ft_strlcpy(out, *headline, rem_len + 1);
	temp = ft_strdup(ptrline + 1);
	if (!temp)
	{
		free(out);
		return (NULL);
	}
	free(*headline);
	*headline = temp;
	return (out);
}

char	*allocate_noline(char **headline)
{
	char	*out;

	out = ft_strdup(*headline);
	free(*headline);
	*headline = NULL;
	return (out);
}

void	free_helper(char **headline)
{
	if (*headline)
	{
		if(!*headline[0])
		{
			free(*headline);
			*headline = NULL;
		}
		return;
	}
	free(*headline);
	*headline = NULL;
	return;
}

char	*get_next_line(int fd)
{
	static char	*headline;
	char		*out;
	int			bytes_read;

	bytes_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!headline)
	{
		headline = malloc(1);
		if (!headline)
			return (NULL);
		headline[0] = '\0';
	}
	create_line(&headline, fd, &bytes_read);
	free_helper(&headline);
	if(!headline)
		return NULL;
	if (ft_strchr(headline, '\n'))
		out = allocate_line(&headline);
	else
		out = allocate_noline(&headline);
	return (out);
}
