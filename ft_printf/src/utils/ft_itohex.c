/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 19:41:23 by ylai              #+#    #+#             */
/*   Updated: 2024/07/25 00:02:22 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_itohex(unsigned long n, char *base)
{
	char				*hex;
	unsigned long		tmp;
	long long			len;

	len = 0;
	if (n < 0)
		n = -n;
	tmp = n;
	if (n == 0)
		len = 1;
	while (n > 0L)
	{
		n /= 16L;
		len++;
	}
	hex = (char *) malloc(sizeof(char) * (len + 1));
	if (hex == NULL)
		return (NULL);
	hex[len] = '\0';
	while (len--)
	{
		hex[len] = base[tmp % 16];
		tmp = tmp / 16;
	}
	return (hex);
}
