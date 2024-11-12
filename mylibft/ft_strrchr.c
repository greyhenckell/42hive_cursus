/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenckel <fhenckel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:19:38 by fhenckel          #+#    #+#             */
/*   Updated: 2024/10/29 17:46:38 by fhenckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

//#include <stdio.h>
//#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	size_t	len;

	p = (char *)s;
	len = ft_strlen(s);
	if (c == 0)
		return (p + len);
	while ((len--) > 0)
	{
		if (p[len] == (char)c)
			return (p + len);
	}
	return (NULL);
}
/*
int	main(void)
{
	const char *s1 = "hello world";
	printf("t1:%s\n", ft_strrchr(s1, 'd'));
	printf("%s\n", strrchr(s1, 'd'));
	printf("-------\n");
	const char *s2 = "banana";
		printf("t2:%s\n", ft_strrchr(s2, 'a'));
		printf("%s\n", strrchr(s2, 'a'));
		printf("-------\n");
	const char *s3 = "openai";
		printf("t3:%s\n", ft_strrchr(s3, 'z'));
		printf("(null)\n");
		printf("-------\n");
	const char *s4 = "x";
		printf("t4:%s\n", ft_strrchr(s4, 'x'));
		printf("%s\n", strrchr(s4, 'x'));
		printf("-------\n");
	const char *s5 = "";
		printf("%s\n", ft_strrchr(s5, 'x'));
		printf("%s\n", strrchr(s5, 'x'));
		printf("-------\n");

}*/
