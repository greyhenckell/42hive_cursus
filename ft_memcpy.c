/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenckel <fhenckel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:51:36 by fhenckel          #+#    #+#             */
/*   Updated: 2024/10/29 14:32:27 by fhenckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*psrc;
	char	*pdest;
	int		i;

	psrc = (char *) src;
	pdest = (char *) dest;
	i = 0 ;
	while (i < (int)n)
	{
		pdest[i] = psrc[i];
		i++;
	}
	return ((void *)pdest);
}
/*
int main()
{
	char d[10];
	char s[] = "hi hiver!";
	char *out  = memcpy(d, s, 20);
	printf("%s\n", out);
}*/
