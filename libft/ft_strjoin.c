/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 00:20:27 by ylai              #+#    #+#             */
/*   Updated: 2024/05/22 13:24:40 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*space;
	size_t	i;
	size_t	s1_l;
	size_t	s2_l;

	i = 0;
	s1_l = ft_strlen(s1);
	s2_l = ft_strlen(s2);
	len = s1_l + s2_l;
	space = (char *) malloc((len + 1) * sizeof(char));
	if (space == NULL)
		return (0);
	while (i < s1_l)
	{
		space[i] = s1[i];
		i++;
	}
	while (i < s2_l)
	{
		space[s1_l + i] = s2[i];
		i++;
	}
	space[s1_l + i] = '\0';
	return (space);
}
