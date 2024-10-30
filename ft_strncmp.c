/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenckel <fhenckel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:48:21 by fhenckel          #+#    #+#             */
/*   Updated: 2024/10/30 17:42:10 by fhenckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;
	char			*p1;
	char			*p2;

	p1 = (char *)s1;
	p2 = (char *)s2;
	i = 0;
	while (i < n && p1[i] == p2[i] && (p1[i]!='\0' || p2[i] != '\0'))
		i++;
	return ((p1[i] > p2[i]) - (p2[i] > p1[i]));
}
/*
int main()
{
    printf("%d\n", ft_strncmp("hola", "", 6));
    printf("---------\n");
    printf("%d\n", strncmp("hola", "", 6));
}*/
