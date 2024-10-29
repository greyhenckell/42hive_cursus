/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenckel <fhenckel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:54:48 by fhenckel          #+#    #+#             */
/*   Updated: 2024/10/29 18:31:13 by fhenckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *s, int c, size_t n)
{
	char	*p;
	int		i;

	p = (char *)s;
	i = 0;
	while (i < (int) n)
	{
		p[i++] = c;
	}
	p[i] = '\0';
	return (p);
}
/*
int main()
{
	char src[10];
	memset(src, 'a', 5);
	printf("%s\n",src);

}*/
