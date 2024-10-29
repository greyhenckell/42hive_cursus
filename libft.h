/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenckel <fhenckel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:29:51 by fhenckel          #+#    #+#             */
/*   Updated: 2024/10/29 12:53:20 by fhenckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef libft_h
# define libft_h

int	ft_isalpha(int c);
int	ft_isdigit(int c);
int     ft_isalnum(int c);
int     ft_isascii(int c);
int     ft_isprint(int c);

void	*ft_memset(void *s, int c, size_t n);

#endif
