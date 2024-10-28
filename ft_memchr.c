/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenckel <fhenckel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:26:41 by fhenckel          #+#    #+#             */
/*   Updated: 2024/10/28 15:50:03 by fhenckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*p;
	int		i;

	p = (char *)s;
	i = 0;
	while (p[i] != '\0' || i < (int) n)
		if (p[i++] == c)
			return (p + i - 1);
	return (NULL);
}
/*
int main()
{
	char s[] = "hi hiver";
	char *ptr = memchr(s, 'p', 5);
	printf("%s\n", ptr);
}*/
