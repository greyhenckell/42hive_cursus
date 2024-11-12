/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenckel <fhenckel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:48:21 by fhenckel          #+#    #+#             */
/*   Updated: 2024/11/04 10:41:16 by fhenckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	i = 0;
	while ((i < n) && (p1[i] != '\0' || p2[i] != '\0'))
	{
		if (p1[i] != p2[i])
			return ((p1[i] > p2[i]) - (p2[i] > p1[i]));
		i++;
	}
	return (0);
}
/*
int main()
{
    printf("%d\n", ft_strncmp("abcdef", "abcdefghijklmnop", 6));
    printf("---------\n");
    printf("%d\n", strncmp("abcdef", "abcdefghijklmnop", 6));
}*/
