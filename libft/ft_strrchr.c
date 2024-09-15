/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:45:35 by ylai              #+#    #+#             */
/*   Updated: 2024/05/22 18:28:36 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locates a character in string.
 *
 * This function finds the last occurance of int `c` in string
 * `s`.
 *
 * @param s Pointer to the string s.
 * @param c Value to find. The value is passed as an int.
 * @return Returns a pointer to the last occurance of the character 'c'
 *         in the string s.
 */
char	*ft_strrchr(const char *s, int c)
{
	char	*s1_cpy;
	size_t	len;

	len = ft_strlen(s);
	s1_cpy = (char *)s;
	while (len--)
	{
		if (s1_cpy[len] == c)
		{
			return (s1_cpy + len);
		}
	}
	return (0);
}
