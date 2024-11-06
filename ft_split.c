//#include <stdio.h>
#include "libft.h"

int	count_items(char const *str, char delim)
{
	int cntword;
	int flag;

	cntword = 0;
	flag = 0;
	while(*str != '\0')
	{
		if(*str != delim && flag == 0)
		{
			flag = 1;
			cntword++;
		}
		else if (*str == delim )
			flag = 0;
		str++;
	}
	return cntword;
	
}

char **ft_split(char const *s, char c)
{
	char **out;
	int array_size;
	int start;
	int end;
	int idx;

	out = NULL;
	start = 0;
	end = 0;
	idx = 0;
	if (c == '\0')
			array_size = 0;
	else
		array_size = count_items(s, c);
	//printf("arrsize:%d\n", array_size);
	out = (char **)malloc((array_size + 1) * sizeof(char *));
	if (out == NULL)
		return NULL;

	if (!array_size)
	{
			out[0] = NULL;
			return out;
	}
	
	while(s[start] != '\0' )
	{
		while(s[start] == c)
			start++;
		end = start;
		while(s[end] != c && s[end] != '\0')
			end++;

		if (end > start)
		{
			out[idx] = (char *)malloc((end - start + 1) * sizeof(char));
			if (out[idx] == NULL)
			{
				while(idx > 0)
				{
					idx--;
					free(out[idx]);
				}
				free(out);
				return (NULL);
			}
			ft_strlcpy(out[idx], s + start, end - start + 1);
			//printf("item:%s ", out[idx]);
			idx++;
		}
		start = end;
	}
	out[idx] = NULL;
	return out;
}
/*
int main()
{
    char **result;
	char	**expected = (char*[6]){"split", "this", "for", "me", "!", NULL};
    result = ft_split("      split       this for   me  !       ", ' '); // '', 'hola', 'como'
    int i = 0;
    while (result[i])
    {
        printf("result:%s\n", result[i]);
		if (strcmp(result[i], expected[i]))
				printf("error item %d",i+1);
		free(result[i]);
        i++;
    }
    free(result);
}*/
