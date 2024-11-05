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
#include <stdio.h>
#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
    char *p1 = (char *)s1;
    char *out;

    int i = 0;

    size_t lenstr = ft_strlen(s1);
    //printf("%zu\n",lenstr);
    out = (char *)malloc((lenstr + 1) * sizeof(char));
    if (out == NULL)
        return NULL;
    while (p1[i] != '\0')
    {
	if(ft_strchr(set, p1[i]))
		i++;
        else
            break;
    }
    p1 = p1 + i;
    //printf("p1_val:%s\n", p1);
    //printf("begintrimmed:%zu\n",lenstr-i);
    while( lenstr-i > 0)
    {
	    if(ft_strchr(set, p1[lenstr-i-1]))
	    	lenstr--;
	    else
	    	break;
    }
    //printf("endtrimmed:%zu\n", lenstr-i);
    ft_strlcpy(out, p1, lenstr-i+1);
    out[i] = '\0';
    return out;
}

int main()
{
	char *s1 = "   \t  \n\n \t\t  \n\n\nHello \t  Please\n Trim me !\n   \n \n \t\t\n  ";
        char *s2 = "Hello \t  Please\n Trim me !";
        char *ret = ft_strtrim(s1, " \n\t");
	printf("%s\n",ret);
	printf("-----------\n");
	printf("%s\n",s2);
}
