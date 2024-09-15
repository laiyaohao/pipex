/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:57:22 by ylai              #+#    #+#             */
/*   Updated: 2024/05/26 17:25:05 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_dest;
	unsigned char	*temp_src;
	size_t			i;

	temp_dest = (unsigned char *)dest;
	temp_src = (unsigned char *)src;
	i = 0;
	if (temp_dest == NULL && temp_src == NULL)
		return (NULL);
	while (i < n)
	{
		*temp_dest = *temp_src;
		temp_src++;
		temp_dest++;
		i++;
	}
	return (dest);
}
