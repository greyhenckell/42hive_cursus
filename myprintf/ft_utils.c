/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenckel <fhenckel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:54:33 by fhenckel          #+#    #+#             */
/*   Updated: 2024/11/07 14:04:55 by fhenckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(long long n, int base, int c)
{
	char				out;
	unsigned long long	temp;

	if (n < 0 && base == 10)
	{
		write(1, "-", 1);
		temp = (unsigned long long)(-n);
	}
	else
		temp = (unsigned long long)n;
	if (temp >= (unsigned long long)base)
		ft_putnbr_base((long long)(temp / base), base, c);
	if ((temp % base) > 9)
		out = c + (temp % base) - 10;
	else
		out = (temp % base) + 48;
	write(1, &out, 1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	i;

	if (start >= ft_strlen(s))
		len = 0;
	i = 0;
	out = (char *)malloc((len + 1) * sizeof(char));
	if (out == NULL)
		return (NULL);
	while (i < len)
	{
		out[i] = *(s + start + i);
		i++;
	}
	out[i] = '\0';
	return (out);
}

void	ft_putchar(char c)
{
	write(1, &c, sizeof(c));
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	*p;
	size_t	i;

	p = (char *)s;
	if (c == 0)
		return (p + ft_strlen(s));
	i = 0;
	while (s[i] != (char)c && s[i] != '\0')
		i++;
	if (s[i] == 0)
		return (NULL);
	return (p + i);
}
