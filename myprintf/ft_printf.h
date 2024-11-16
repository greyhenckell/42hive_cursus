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

int ft_atoi(const char *nptr);
char *ft_strchr(const char *s, int c);
size_t ft_strlen(const char *s);
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
char *ft_substr(char const *s, unsigned int start, size_t len);
char *ft_itoa(int n);
char *ft_uitoa(unsigned int n, char c);
void ft_putunbr(unsigned int n, char *out);
void ft_puthex(unsigned int n, char *out);
void ft_putchar(char c);
char *ft_ultoa(unsigned long n, char c);
void ft_putlonghex(unsigned long n, char *out);
int ft_printf(const char *fmt, ...);
size_t ft_strlcpy(char *dst, const char *src, size_t size);
void *ft_memset(void *s, int c, size_t n);
int ft_toupper(int c);
void ft_putnbr_base(long long n, int base, int c);
int ft_unsigned_numlen(unsigned long n, int base);
int ft_numlen(long long n, int base);

#endif
