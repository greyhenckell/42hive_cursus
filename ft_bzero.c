/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenckel <fhenckel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:08:36 by fhenckel          #+#    #+#             */
/*   Updated: 2024/10/29 14:33:49 by fhenckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_bzero(void *s, size_t n)
{
	char	*p;
	size_t	i;

	p = (char *)s;
	i = 0;
	while (i < n)
		p[i++] = 0;
}
/*
int main()
{
	char s[] = "hola";
	bzero(s, 2);
	printf("%s\n",s);
}*/
