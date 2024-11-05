/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenckel <fhenckel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:01:50 by fhenckel          #+#    #+#             */
/*   Updated: 2024/11/05 18:59:07 by fhenckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//#include <stdio.h>
#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
	char *out;
	int i = 0;
	size_t lenstr;
   
	lenstr = ft_strlen(s1);
	while (s1[i] != '\0')
    	{
		if(ft_strchr(set, s1[i]))
			i++;
        	else
            		break;
    	}
    	s1 = s1 + i;
    	while( lenstr-i > 0)
    	{
		if(ft_strchr(set, s1[lenstr-i-1]))
			lenstr--;
	    	else
	    		break;
    	}
    //printf("endtrimmed:%zu\n", lenstr-i);
    	out = (char *)malloc((lenstr-i + 1) * sizeof(char));
    	if (out == NULL)
        	return NULL;
    	ft_strlcpy(out, s1, lenstr-i+1);
    	return out;
}
/*
int main()
{
	char *s1 = "-+-+hola-+-+";
        char *s2 = "hola";
        char *ret = ft_strtrim(s1, "-+");
	printf("%s\n",ret);
	printf("-----------\n");
	printf("%s\n",s2);
}*/
