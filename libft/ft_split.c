/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 21:39:33 by ylai              #+#    #+#             */
/*   Updated: 2024/05/25 18:21:10 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	allocate(char **s, int index, int len)
{
	int	i;

	i = 0;
	s[index] = (char *)malloc(sizeof(char) * (len + 1));
	if (s[index] == NULL)
	{
		while (i < index)
		{
			free(s[i]);
			i++;
		}
		free(s);
		return (1);
	}
	return (0);
}

int	fill(char const *s, char **ans, char c)
{
	size_t	len;
	int		i;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			len++;
			s++;
		}
		if (len)
		{
			if (allocate(ans, i, len))
				return (1);
			ft_strlcpy(ans[i], s - len, len + 1);
		}
		i++;
	}
	return (0);
}

size_t	num_o(char const *s, char c)
{
	size_t	num;
	int		inside;

	num = 0;
	while (*s)
	{
		inside = 0;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			if (inside == 0)
			{
				num++;
				inside = 1;
			}
			s++;
		}
	}
	return (num);
}

char	**ft_split(char const *s, char c)
{
	char	**ans;
	int		size;

	if (s == NULL)
		return (NULL);
	size = num_o(s, c);
	ans = (char **)malloc(sizeof(char *) * (size + 1));
	if (ans == NULL)
		return (NULL);
	ans[size] = NULL;
	if (fill(s, ans, c))
	{
		return (NULL);
	}
	return (ans);
}
