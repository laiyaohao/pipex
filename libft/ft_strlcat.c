/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 21:53:20 by ylai              #+#    #+#             */
/*   Updated: 2024/05/26 18:16:36 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	ta_len;
	size_t	i;
	size_t	src_len;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	ta_len = size - dst_len - 1;
	if (ta_len <= 0 || src_len == 0)
		return (dst_len);
	while (i < ta_len && src[i])
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (src_len == i)
		dst[dst_len + i] = 0;
	return (dst_len + src_len);
}
