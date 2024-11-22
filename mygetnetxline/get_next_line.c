#include "get_next_line.h"
#include <stdio.h>

// char 4bytes , default buffer_size = 1024
void	create_line(char **ptrline, int fd)
{
	char	*temp;
	char	*buff_content;
	int		bytes_read;

	// create line
	temp = NULL;
	buff_content = NULL;
	bytes_read = 0;
	while (ft_strchr(*ptrline, '\n') == NULL)
	{
		buff_content = malloc((BUFFER_SIZE + 1));
		if (!buff_content)
			return ;
		bytes_read = read(fd, buff_content, BUFFER_SIZE);
		if (!bytes_read)
		{
			//printf("nothing to read\n");
			free(buff_content);
			free(*ptrline);
			*ptrline = NULL;
			return ;
		}
		else if (bytes_read == -1)
		{
			free(buff_content);
			return ;
		}
		else
			buff_content[bytes_read] = '\0';
		//  join
		// free(temp);
		temp = ft_strjoin(*ptrline, buff_content);
		free(*ptrline);
		free(buff_content);
		*ptrline = temp;
	}
}
char	*get_next_line(int fd)
{
	static char	*headline;
	char		*out = NULL;
	char		*temp;
	size_t		rem_len;

	temp = NULL;
	rem_len = 0;

	if (!headline)
	{
		//printf("here\n");
		headline = malloc(1);
		headline[0] = '\0';
	}
	if(!headline)
		return (NULL);

	// create space for struct line
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	//printf("--%s\n", headline);
	create_line(&headline, fd);	
	if (headline == 0)
	{
		//free(headline);
		return (NULL);
	}
	//   check if newline exists
	if (ft_strchr(headline, '\n'))
	{
		rem_len = ft_strlen(ft_strchr(headline, '\n') + 1);
		if (rem_len > 0)
		{
			out = malloc(((ft_strlen(headline) - rem_len) + 1) * sizeof(char));
			if (!out)
				return (NULL);
			ft_strlcpy(out, headline, ft_strlen(headline) - rem_len);
			temp = malloc((rem_len + 1) * sizeof(char));
			if (temp)
				ft_strlcpy(temp, ft_strchr(headline, '\n') + 1, rem_len + 1);
			free(headline);
			headline = temp;
		}
		else
		{
			out = malloc(((ft_strlen(headline) - rem_len) + 1) * sizeof(char));
			if (!out)
				return (NULL);
			ft_strlcpy(out, headline, ft_strlen(headline) - rem_len);
			free(headline);
			headline = malloc(1);
			headline[0] = '\0';
		}
	}
	return (out);
}

int	main(void)
{
	char *line;
	int fd = open("test1.txt", O_RDWR);

	while ((1))
	{
		line = get_next_line(fd);
		printf("%s\n", line);
		if (line)
			free(line);
		if (!line)
			break;
	}

	close(fd);
	return (0);
}