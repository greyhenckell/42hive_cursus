/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenckel <fhenckel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:05:47 by fhenckel          #+#    #+#             */
/*   Updated: 2024/10/29 17:23:32 by fhenckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	*p;
	int		i;

	p = (char *)s;
	i = 0;
	if (c == '\0')
		return ("\0");
	while (s[i] != '\0' && s[i] != c)
		i++;
	if (s[i])
		return (p + i);
	return (NULL);
}
/*
int main()
{
    printf("%s\n", strchr("hola", 'l'));
}*/
