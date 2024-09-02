/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 13:42:24 by ylai              #+#    #+#             */
/*   Updated: 2024/07/26 19:38:49 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		ans;
	size_t	i;
	va_list	args;

	va_start(args, str);
	i = 0;
	ans = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			ft_putchar(str[i], &ans);
		}
		else
		{
			ft_format(str, &ans, &i, args);
			i++;
		}
		i++;
	}
	va_end(args);
	return (ans);
}
