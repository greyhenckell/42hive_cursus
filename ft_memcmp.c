/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenckel <fhenckel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:38:08 by fhenckel          #+#    #+#             */
/*   Updated: 2024/10/29 18:30:13 by fhenckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*ps1;
	char	*ps2;
	int		i;

	ps1 = (char *)s1;
	ps2 = (char *)s2;
	i = 0;
	while ((i < (int)n) && (ps1[i] == ps2[i]))
		i++;
	return (ps1[i] - ps2[i]);
}
/*
int main()
{
	char e1[50] = "welcome to hive";
	char e2[50] = "welcome to hive";
	printf("%d\n", ft_memcmp(e1,e2,30));
	printf("%d\n", memcmp(e1,e2,30));
}*/
