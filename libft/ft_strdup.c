/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 00:17:16 by ylai              #+#    #+#             */
/*   Updated: 2024/05/25 11:02:52 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*ans;
	size_t	i;

	i = 0;
	len = ft_strlen(s);
	ans = (char *) malloc(len * sizeof(char));
	while (i < len)
	{
		ans[i] = s[i];
		i++;
	}
	return (ans);
}
