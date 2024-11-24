#include "get_next_line.h"
#include <stdio.h>

void create_line(char **ptrline, int fd, int *bytes_read)
{
	char *temp;
	char *buff_content;

	while (*bytes_read > 0 && ft_strchr(*ptrline, '\n') == NULL)
	{
		buff_content = malloc((BUFFER_SIZE + 1));
		if (!buff_content)
			return;
		*bytes_read = read(fd, buff_content, BUFFER_SIZE);
		if (*bytes_read == -1)
		{
			free(buff_content);
			return;
		}
		buff_content[*bytes_read] = '\0';
		temp = ft_strjoin(*ptrline, buff_content);
		free(*ptrline);
		free(buff_content);
		*ptrline = temp;
	}
}

char *allocate_line(char **headline)
{
	char *temp;
	char *out;
	size_t rem_len;
	char *ptrline;

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

char *allocate_noline(char **headline)
{
	char *out;
	out = ft_strdup(*headline);
	free(*headline);
	*headline = NULL;
	return (out);
}
char *get_next_line(int fd)
{
	static char *headline;
	char *out;
	int bytes_read = 1;

	out = NULL;
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
	if (!headline[0])
	{
		free(headline);
		headline = NULL;
		return (NULL);
	}
	if (ft_strchr(headline, '\n'))
		out = allocate_line(&headline);
	else
		out = allocate_noline(&headline);
	return (out);
}
/*
int main(void)
{
	char *line;
	int fd = open("test1.txt", O_RDWR);

	while ((1))
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (line)
			free(line);
		if (!line)
			break;
	}

	close(fd);
	return (0);
}*/