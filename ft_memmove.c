/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenckel <fhenckel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:38:44 by fhenckel          #+#    #+#             */
/*   Updated: 2024/10/29 10:06:41 by fhenckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*pdest;
	char	*psrc;
	int		i;

	pdest = (char *) dest;
	psrc = (char *)src;
	if (pdest > psrc)
	{
		while (n > 0)
		{
			n--;
			pdest[n] = psrc[n];
		}
	}
	else
	{
		i = 0;
		while (i < (int)n)
		{
			pdest[i] = psrc[i];
			i++;
		}
	}
	return (pdest);
}
/*
int main()
{
	//char dest_str[] = "Tutorialspoint"; 
	char src_str[] = "ABCDE!!";
	printf("size:%lu\ndest_src_5:%s\n",sizeof(src_str), src_str+5);
	memmove(src_str+5, src_str, sizeof(src_str));
	printf("%s\n", src_str);
}*/
