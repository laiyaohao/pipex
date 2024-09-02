/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:58:43 by ylai              #+#    #+#             */
/*   Updated: 2024/07/26 19:37:46 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

int		ft_printf(const char *str, ...);
char	*ft_itoa(int n);
char	*ft_ltoa(long long n);
char	*ft_itohex(unsigned long n, char *base);
int		ft_isnegative(int n);
long	ft_abs(long i);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	ft_putchar(char c, int *ans);
void	ft_putstr(const char *str, int *ans, size_t *i, char c);
char	*ft_strdup(const char *s1);
void	ft_format(const char *str, int *ans, size_t *i, va_list args);
int		ft_find_len(int n);
void	ft_print_int(va_list args, int *ans);
void	ft_print_uint(va_list args, int *ans);
void	ft_print_char(va_list args, int *ans);
void	ft_print_str(va_list args, int *ans);
void	ft_print_add(va_list args, int *ans);
void	ft_print_hex(va_list args, int *ans, char c);

#endif