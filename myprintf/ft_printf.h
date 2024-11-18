/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenckel <fhenckel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:29:51 by fhenckel          #+#    #+#             */
/*   Updated: 2024/11/08 12:28:00 by fhenckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <limits.h>
#include <stdlib.h>
#include <unistd.h>


char *ft_strchr(const char *s, int c);
size_t ft_strlen(const char *s);
void ft_putunbr(unsigned int n, char *out);
void ft_putnbr_base(long long n, int base, int c);
int ft_unsigned_numlen(unsigned long n, int base);
int ft_numlen(long long n, int base);
void	ft_putchar(char c);

int ft_printf(const char *fmt, ...);

#endif
