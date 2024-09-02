/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 13:40:27 by ylai              #+#    #+#             */
/*   Updated: 2024/07/24 15:10:33 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_itoa(int n)
{
	int		len;
	int		neg;
	long	modulo;
	char	*ans;

	len = ft_find_len(n);
	if (n == 0)
		len = 1;
	modulo = 10;
	neg = ft_isnegative(n);
	ans = (char *) malloc(sizeof(char) * (len + neg + 1));
	if (ans == NULL)
		return (NULL);
	ans[len + neg] = '\0';
	while (len--)
	{
		ans[len + neg] = ((ft_abs(n % modulo)) / (modulo / 10)) + 48;
		modulo *= 10;
	}
	if (neg)
		ans[0] = '-';
	return (ans);
}
