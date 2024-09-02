/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 13:46:25 by ylai              #+#    #+#             */
/*   Updated: 2024/07/24 23:22:03 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

// Function that prints characters from str until it reaches character c
// or the end of the string. 
// Parameters:
// - str: The input string to print characters from.
// - ans: Pointer to an integer to store the number of characters printed.
// - i: Pointer to a size_t variable representing the current index in the 
// string.
// - c: The character to stop printing at.
void	ft_putstr(const char *str, int *ans, size_t *i, char c)
{
	char	*to_print;
	int		index;

	index = 0;
	if (str == NULL)
		to_print = ft_strdup("(null)");
	else
		to_print = ft_strdup(str);
	while (to_print[index] && to_print[index] != c)
	{
		ft_putchar(to_print[index], ans);
		*i += 1;
		index++;
	}
	free(to_print);
}
