/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:09:06 by ylai              #+#    #+#             */
/*   Updated: 2024/07/25 19:34:30 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_add(va_list args, int *ans)
{
	void			*add;
	long long		input;
	char			*to_print;
	char			hex[17];
	size_t			index;

	index = 0;
	add = va_arg(args, void *);
	input = (unsigned long)add;
	ft_strlcpy(hex, "0123456789abcdef", 17);
	if (input != 0)
	{
		ft_putchar('0', ans);
		ft_putchar('x', ans);
		to_print = ft_itohex(input, hex);
	}
	else
		to_print = ft_strdup("(nil)");
	ft_putstr(to_print, ans, &index, '\0');
	free(to_print);
}
