#include "libft.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (argv[2] == 'atoi')
		{
			printf("%d\n", ft_atoi("-4000000000"));
			printf("%d\n", atoi("-4000000000"));
			printf("%ld\n", strtol("-4000000000", 0, 10));
			printf("%d\n", (int)strtol("-4000000000", 0, 10));
		}

		if (argv[2] == 'calloc')
		{
			char s[] = "hola welcome";
			char *ptr;

			ptr = s;

			printf("%s\n", ptr);
			ptr = (char *)calloc(50000000000000, 10);
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

		if (argv[2] == 'itao')
		{
			char *s = ft_itoa(0);
			printf("%s\n", s);
			free(s);
		}

		if (argv[2] == 'lstadd_front')
		{
			t_list *h;
			t_list **lst;

			lst = &h;

			h = ft_lstnew("B");
			h->next = ft_lstnew("C");
			ft_lstadd_front(lst, ft_lstnew("A"));
			while (h != NULL)
			{
				printf("%s ", (char *)h->content);
				h = h->next;
			}
		}
		if (argv[2] == 'memove')
		{
			// char dest_str[] = "Tutorialspoint";
			char src_str[40] = "fgdgf";
			printf("size:%lu\ndest_src_5:%s\n", sizeof(src_str), src_str + 5);
			// ft_memmove(src_str+5, src_str, strlen(src_str)+1);
			memmove(0, src_str, sizeof(10));
			printf("%s\n", src_str);
		}
		if (argv[2] == 'putendl_fd')
		{
			ft_putendl_fd("Hello, world!", 1);

			// Example: Writing to a file
			int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
			if (fd == -1)
				return (1);
			printf("fd:%d\n", fd);
			ft_putendl_fd("Writing to a file!", fd);

			close(fd);
			return (0);
		}
		if (argv[2] == 'split')
		{
			char **result;
			char **expected = (char *[6]){"split", "this", "for", "me", "!",
				NULL};
			result = ft_split("      split       this for   me  !       ", ' ');
			// '',
			'hola', 'como' int i = 0;
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
		if (argv[2] == 'strjoin')
		{
			char *src1 = "hello";
			char *src2 = "_welcome";
			printf("%zu + %zu\n", ft_strlen(src1), ft_strlen(src2));
			char *res = ft_strjoin(src1, src2);
			printf("%s\n", res);
			free(res);
		}
		if (argv[2] == 'strmapi')
		{
			char *strm = ft_strmapi("hola", ft_toupper);
			printf("%s\n", strm);
			free(strm);
		}
		if (argv[2] == 'strtrim')
		{
			char *s1 = "-+-+hola-+-+";
			char *s2 = "hola";
			char *ret = ft_strtrim(s1, "-+");
			printf("%s\n", ret);
			printf("-----------\n");
			printf("%s\n", s2);
		}
		if (argv[2] == 'strlcat')
		{
			char dst[13] = "Hello, ";
			char src[] = "world!";
			size_t size = 13;

			ft_strlcat(dst, src, size);
			printf("%s\n", dst); // Expected: "Hello, world!"
		}
	}
}