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

#ifndef LIBFT_H
#define LIBFT_H

#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isalnum(int c);
int ft_isascii(int c);
int ft_isprint(int c);
int ft_toupper(int c);
int ft_tolower(int c);
int ft_atoi(const char *nptr);
int ft_strncmp(const char *s1, const char *s2, unsigned int n);
char *ft_strchr(const char *s, int c);
char *ft_strrchr(const char *s, int c);
char *ft_strnstr(const char *big, const char *little,
				 size_t len);
char *ft_strdup(char *src);
void *ft_memchr(const void *s, int c, size_t n);
void *ft_memset(void *s, int c, size_t n);
void ft_bzero(void *s, size_t n);
void *ft_memcpy(void *dest, const void *src, size_t n);
void *ft_memmove(void *dest, const void *src, size_t n);
void *ft_calloc(size_t nmemb, size_t size);
size_t ft_strlen(const char *s);
size_t ft_strlcpy(char *dst, const char *src, size_t size);
size_t ft_strlcat(char *dst, const char *src, size_t size);
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
char *ft_substr(char const *s, unsigned int start, size_t len);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strtrim(char const *s1, char const *set);
char **ft_split(char const *s, char c);
char *ft_itoa(int n);
char *ft_uitoa(unsigned int n, char c);
void ft_striteri(char *s, void (*f)(unsigned int, char *));
void ft_putstr_fd(char *s, int fd);
void ft_putunbr(unsigned int n, char *out);
void ft_puthex(unsigned int n, char *out);
void ft_putchar(char c);

#endif
