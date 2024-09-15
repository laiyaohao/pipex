/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:38:23 by ylai              #+#    #+#             */
/*   Updated: 2024/05/25 11:19:19 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locates a character in string.
 *
 * This function finds the first occurance of int `c` in string
 * `s`.
 *
 * @param s Pointer to the string s.
 * @param c Value to find. The value is passed as an int.
 * @return Returns a pointer to the first occurance of the character 'c'
 *         in the string s.
 */
char	*ft_strchr(const char *s, int c)
{
	char	*s1_cpy;

	s1_cpy = (char *)s;
	while (*s1_cpy)
	{
		if (*s1_cpy == c)
		{
			return (s1_cpy);
		}
		s1_cpy++;
	}
	if (c != 0)
	{
		return (0);
	}
	return (s1_cpy);
}
