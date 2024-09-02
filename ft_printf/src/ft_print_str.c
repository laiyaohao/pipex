/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:36:49 by ylai              #+#    #+#             */
/*   Updated: 2024/07/25 19:34:48 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_str(va_list args, int *ans)
{
	char	*str;
	size_t	index;

	str = va_arg(args, char *);
	index = 0;
	ft_putstr(str, ans, &index, '\0');
}
