#include <stdlib.h>
//#include <stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (*src)
	{
		*(dest + i++) = *src++;
	}
	dest[i] = '\0';
	return (dest);
}

int	counter(char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	len_strs(int size, char **strs)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < size)
	{
		len += counter(strs[i]);
		i++;
	}
	return (len);
}	

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*dest;
	int		i;
	int		total_len;

	i = 0;
	total_len = len_strs(size, strs) + (size - 1) * counter(sep) + 1;
	if (total_len <= 0)
		total_len = 1;
	dest = (char *) malloc(total_len * sizeof(char));
	if (dest == NULL)
		return (NULL);
	dest[0] = '\0';
	i = 0 ;
	while (i < size)
	{
		ft_strcat(dest, strs[i]);
		if (i < size - 1)
			ft_strcat(dest, sep);
		i++;
	}
	return (dest);
}
/*
int main()
{
	char *out[] = {"", "como", "estas"};
	char *res = ft_strjoin(0, out, "");

	printf("%s", res);
	free(res);
}*/
