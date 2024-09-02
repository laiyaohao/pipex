/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 22:37:34 by ylai              #+#    #+#             */
/*   Updated: 2024/07/26 19:35:51 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(const char *str, int *ans, size_t *i, va_list args)
{
	if (str[*i + 1] == 'i' || str[*i + 1] == 'd')
		ft_print_int(args, ans);
	else if (str[*i + 1] == 'c')
		ft_print_char(args, ans);
	else if (str[*i + 1] == 's')
		ft_print_str(args, ans);
	else if (str[*i + 1] == 'u')
		ft_print_uint(args, ans);
	else if (str[*i + 1] == 'x' || str[*i + 1] == 'X')
		ft_print_hex(args, ans, str[*i + 1]);
	else if (str[*i + 1] == 'p')
		ft_print_add(args, ans);
	else
		ft_putchar(str[*i + 1], ans);
}
