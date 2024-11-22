#include "get_next_line.h"
#include <stdio.h>

void	create_line(char **ptrline, int fd)
{
	char	*temp;
	char	*buff_content;
	int		bytes_read;

	temp = NULL;
	buff_content = NULL;
	bytes_read = 0;
	while (ft_strchr(*ptrline, '\n') == NULL)
	{
		buff_content = malloc((BUFFER_SIZE + 1));
		if (!buff_content)
			return ;
		bytes_read = read(fd, buff_content, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(buff_content);
			free(*ptrline);
			*ptrline = NULL;
			return ;
		}
		buff_content[bytes_read] = '\0';
		temp = ft_strjoin(*ptrline, buff_content);
		free(*ptrline);
		free(buff_content);
		*ptrline = temp;
	}
}

char	*allocate_line(char **headline)
{
	char	*temp;
	char	*out;
	size_t	rem_len;

	rem_len = ft_strlen(ft_strchr(*headline, '\n') + 1);
	out = malloc(((ft_strlen(*headline) - rem_len) + 1) * sizeof(char));
	if (!out)
		return (NULL);
	ft_strlcpy(out, *headline, ft_strlen(*headline) - rem_len+1);
	temp = malloc((rem_len + 1) * sizeof(char));
	if (temp)
		ft_strlcpy(temp, ft_strchr(*headline, '\n') + 1, rem_len+1);
	free(*headline);
	*headline = temp;
	return (out);
}
char	*get_next_line(int fd)
{
	static char	*headline;
	char		*out;

	out = NULL;
	if (!headline)
	{
		headline = malloc(1);
		headline[0] = '\0';
	}
	if (!headline)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	create_line(&headline, fd);
	if (headline == 0)
		return (NULL);
	if (ft_strchr(headline, '\n'))
		out = allocate_line(&headline);
	return (out);
}
int	main(void)
{
	char *line;
	int fd = open("no_nl.txt", O_RDWR);

	while ((1))
	{
		line = get_next_line(fd);
		printf("->nl:%s", line);
		if (line)
			free(line);
		if (!line)
			break ;
	}

	close(fd);
	return (0);
}