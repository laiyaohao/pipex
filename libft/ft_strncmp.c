/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 20:33:24 by ylai              #+#    #+#             */
/*   Updated: 2024/05/25 18:25:26 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s1u;
	unsigned char	*s2u;
	size_t			i;

	i = 0;
	s1u = (unsigned char *)s1;
	s2u = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n && s1u[i] == s2u[i])
	{
		i++;
	}
	return (s1u[i] - s2u[i]);
}
