/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:22:51 by ylai              #+#    #+#             */
/*   Updated: 2024/05/19 22:00:53 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*big_cp;
	size_t	i;
	size_t	j;
	size_t	l_l;

	i = 0;
	big_cp = (char *)big;
	l_l = ft_strlen(little);
	while (i < len)
	{
		j = 0;
		if (big_cp[i] == little[j])
		{
			while (big_cp[i + j] == little[j] && j < l_l)
			{
				j++;
			}
			if (j == l_l)
			{
				return (big_cp + i);
			}
		}
	}
	return (0);
}
