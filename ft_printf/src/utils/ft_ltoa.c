/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 13:40:27 by ylai              #+#    #+#             */
/*   Updated: 2024/07/24 23:28:55 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	find_len(long long n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int	is_negative(long long n)
{
	if (n < 0)
		return (1);
	return (0);
}

char	*ft_ltoa(long long n)
{
	int		len;
	int		neg;
	long	modulo;
	char	*ans;

	len = find_len(n);
	if (n == 0)
		len = 1;
	modulo = 10;
	neg = is_negative(n);
	ans = (char *) malloc(sizeof(char) * (len + neg + 1));
	if (ans == NULL)
		return (NULL);
	ans[len + neg] = '\0';
	while (len--)
	{
		ans[len + neg] = ((ft_abs(n % modulo)) / (modulo / 10L)) + 48;
		modulo *= 10;
	}
	if (neg)
		ans[0] = '-';
	return (ans);
}
