#include "libft.h"
#include <bsd/string.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

// cc main.c -I. -L. -lft -o outmain

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		if (ft_strncmp(argv[1], "atoi", ft_strlen(argv[1])) == 0)
		{
			printf("%d\n", ft_atoi("-4000000000"));
			printf("%d\n", atoi("-4000000000"));
			printf("%ld\n", strtol("-4000000000", 0, 10));
			printf("%d\n", (int)strtol("-4000000000", 0, 10));
		}

		if (ft_strncmp(argv[1], "calloc", ft_strlen(argv[1])) == 0)
		{
			char s[] = "hola welcome";
			char *ptr;

			ptr = s;

			printf("%s\n", ptr);
			ptr = (char *)ft_calloc(50000000000000, 10);
			if (ptr == NULL)
				printf("calloc not allocated\n");
			else
				printf("ptr created\n");
			int i = 0;
			while (i < 20)
			{
				printf(":%c\n", ptr[i]);
				i++;
			}
			free(ptr);
		}

		if (ft_strncmp(argv[1], "itoa", ft_strlen(argv[1])) == 0)
		{
			char *s = ft_itoa(0);
			printf("%s\n", s);
			free(s);
		}

		if (ft_strncmp(argv[1], "memmove", ft_strlen(argv[1])) == 0)
		{
			// char dest_str[] = "Tutorialspoint";
			char src_str[40] = "fgdgf";
			printf("size:%lu\ndest_src_5:%s\n", sizeof(src_str), src_str + 5);
			// ft_memmove(src_str+5, src_str, strlen(src_str)+1);
			ft_memmove(0, src_str, sizeof(10));
			printf("%s\n", src_str);
		}
		if (ft_strncmp(argv[1], "putendl_fd", ft_strlen(argv[1])) == 0)
		{
			ft_putendl_fd("Hello, world!", 1);

			int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
			if (fd == -1)
				return (1);
			printf("fd:%d\n", fd);
			ft_putendl_fd("Writing to a file!", fd);

			close(fd);
			return (0);
		}
		if (ft_strncmp(argv[1], "split", ft_strlen(argv[1])) == 0)
		{
			char **result;
			char **expected = (char *[6]){"split", "this", "for", "me", "!",
				NULL};
			result = ft_split("      split       this for   me  !       ", ' ');
			int i = 0;
			while (result[i])
			{
				printf("result:%s\n", result[i]);
				if (strcmp(result[i], expected[i]))
					printf("error item %d", i + 1);
				free(result[i]);
				i++;
			}
			free(result);
		}
		if (ft_strncmp(argv[1], "strjoin", ft_strlen(argv[1])) == 0)
		{
			char *src1 = "hello";
			char *src2 = "_welcome";
			printf("src1:%zu + src2:%zu\n", ft_strlen(src1), ft_strlen(src2));
			char *res = ft_strjoin(src1, src2);
			printf("%s\n", res);
			free(res);
		}

		if (ft_strncmp(argv[1], "strtrim", ft_strlen(argv[1])) == 0)
		{
			char *s1 = "-+-+hola-+-+";
			char *s2 = "hola";
			char *ret = ft_strtrim(s1, "-+");
			printf("%s\n", ret);
			printf("-----------\n");
			printf("%s\n", s2);
		}
		if (ft_strncmp(argv[1], "strlcat", ft_strlen(argv[1])) == 0)
		{
			printf("running strlcat\n");
			char b[7] = "nyan !";
			int r = ft_strlcat(((void *)0), b, 0);
			printf("%d\n", r);
		}
	}
}