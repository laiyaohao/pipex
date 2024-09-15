/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:23:34 by ylai              #+#    #+#             */
/*   Updated: 2024/05/26 15:22:01 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_islower(int c)
{
	if (c <= 'z' && c >= 'a')
	{
		return (1);
	}
	return (0);
}

static int	ft_isupper(int c)
{
	if (c <= 'Z' && c >= 'A')
	{
		return (1);
	}
	return (0);
}

int	ft_isalpha(int c)
{
	if ((ft_islower(c)) || (ft_isupper(c)))
	{
		return (1);
	}
	return (0);
}
