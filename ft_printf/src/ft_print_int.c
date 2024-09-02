/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 13:50:56 by ylai              #+#    #+#             */
/*   Updated: 2024/07/25 19:34:44 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Function that prints an integer from the va_list args to the standard
// output. 
// It takes a va_list args, an int pointer ans to keep track of the total
// characters printed, 
// and a size_t pointer i to track the current index in the format string.
void	ft_print_int(va_list args, int *ans)
{
	char	*to_print;
	size_t	index;

	index = 0;
	to_print = ft_itoa(va_arg(args, int));
	ft_putstr(to_print, ans, &index, '\0');
	free(to_print);
	to_print = NULL;
}
