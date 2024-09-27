/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 17:38:02 by ylai              #+#    #+#             */
/*   Updated: 2024/09/08 17:38:07 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	num_arg(int argc)
{
	if (argc != 5)
	{
		ft_printf("Wrong number of arguments\nUsage: ./pipex infile cmd1 cmd2 \
outfile\n");
		return (1);
	}
	return (0);
}
