#include "get_next_line.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	char *line;
    (void)argc;

	int fd = open(argv[1], O_RDWR);

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
}