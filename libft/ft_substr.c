/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 20:43:17 by ylai              #+#    #+#             */
/*   Updated: 2024/05/22 18:51:43 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates (with `malloc(3)`) and returns a substring
 *        from the string `s`. The substring begins at index `start`
 *        and is of maximum size `len`.
 * @param s  The string from which to create the substring.
 * @param start The start index of the substring in the string `s`.
 * @param len The maximum length of the substring.
 * @return Returns the substring
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ans;

	i = 0;
	ans = (char *)malloc((len + 1) * (sizeof(char)));
	if (ans == NULL)
	{
		return (NULL);
	}
	while (i < len)
	{
		ans[i] = s[start + i];
		i++;
	}
	ans[start + i] = '\0';
	return (ans);
}
