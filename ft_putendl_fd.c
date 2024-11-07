#include <unistd.h>
#include "libft.h"
//#include <fcntl.h>
void ft_putendl_fd(char *s, int fd)
{
	if (!s)
			return;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}
/*
int main() {
    // Example: Writing to standard output (fd = 1)
    ft_putendl_fd("Hello, world!", 1);

    // Example: Writing to a file
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return 1; // Handle error opening file
	printf("fd:%d\n", fd);
	ft_putendl_fd("Writing to a file!", fd);

    close(fd); // Always close the file descriptor after done
    return 0;
}*/
