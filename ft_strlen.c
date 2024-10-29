/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenckel <fhenckel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:54:48 by fhenckel          #+#    #+#             */
/*   Updated: 2024/10/29 12:58:40 by fhenckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t ft_strlen(const char *s)
{
    size_t i;

    i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}


int main()
{
    printf("%zu\n", ft_strlen("hola"));
}
