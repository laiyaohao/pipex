/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:28:42 by ylai              #+#    #+#             */
/*   Updated: 2024/05/25 11:20:56 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	n_cpy;

	if (n < 0)
	{
		n_cpy = -n;
		ft_putchar_fd('-', fd);
	}
	else
	{
		n_cpy = n;
	}
	if (n_cpy < 10)
	{
		ft_putchar_fd((n_cpy + 48), fd);
	}
	else
	{
		ft_putnbr_fd((n_cpy / 10), fd);
		ft_putnbr_fd((n_cpy % 10), fd);
	}
}
