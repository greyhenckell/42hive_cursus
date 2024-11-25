#include "get_next_line.h"
#include <stdio.h>

//cc -Wall -Werror -Wextra *_bonus.c -fsanitize=address -g -o outbonus
//./outbonus files_bonus/fbonus1 files_bonus/fbonus2 files_bonus/fbonus3

int main(int argc, char **argv)
{
	char *line;

    (void)argc;

	int fd = open(argv[1], O_RDWR);
	int fd2 = open(argv[2], O_RDWR);
	int fd3 = open(argv[3], O_RDWR);

	while ((1))
	{
		line = get_next_line(42);		
		if (line)
		{
			printf("%s", line);
			free(line);
		}
		
		line = get_next_line(fd2);
		if (line)
		{
			printf("\n---calling...another file---\n");	
			printf("%s", line);
			free(line);
		}

		line = get_next_line(fd3);
		if (line)
		{
			printf("\n---calling...another file---\n");	
			printf("%s", line);
			free(line);
		}
		

		if (!line)
			break;
	}
		
	close(fd);
	close(fd2);
	close(fd3);
	return (0);
}