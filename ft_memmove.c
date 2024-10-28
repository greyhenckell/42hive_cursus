/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenckel <fhenckel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:38:44 by fhenckel          #+#    #+#             */
/*   Updated: 2024/10/28 17:26:25 by fhenckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void *ft_memmove(void *dest, const void *src, size_t n)
{
	char	*pdest;
	char	*psrc;
	//char		temp[n];
	int		i;

	pdest = (char *) dest;
	psrc = (char *)src;

	if (pdest > psrc)
	{
		while(n>0)
		{
			n--;
			pdest[n] = psrc[n];
		}
	}
	else
	{

		i = 0;
		while(i < (int)n)
		{
			pdest[i] = psrc[i];
			i++;
		}
		pdest[i] = '\0';
	}
	return (pdest);
}

int main()
{
	//char dest_str[] = "Tutorialspoint"; 
	char src_str[] = "Tutores!!!!!";
	memmove(src_str+5, src_str, sizeof(src_str));
	printf("%s\n", src_str);
}
