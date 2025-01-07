#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>


int is_rectangular(int prevlen, int currentlen)
{
    printf("%d %d \n", prevlen, currentlen);
    if ( prevlen != currentlen)
        return 1;
    return 0;
}

int read_map(char *src)
{
	char *line;    

	int fd = open(src, O_RDWR);

    int numlines = 0;
    int prev_lenline;
	while ((1))
	{
		line = get_next_line(fd);		      
		if (line)
        {
            if (numlines > 0)
            {
                if ( is_rectangular(prev_lenline, ft_strlen(line)) == 1 )
                    return (1);
            }
            prev_lenline = ft_strlen(line);
            numlines++;
			free(line);
        }
		if (!line)
			break;
	}
	close(fd);
    if (numlines == 1)
        return (1);
    return (0);
}