/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 19:06:42 by ylai              #+#    #+#             */
/*   Updated: 2024/10/03 19:06:43 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int open_file(char *filepath, t_data *data)
{
	if (access(filepath, F_OK) == -1)
	{
		ft_printf("Problem accessing the %s.\n", filepath);
		return (1);
	}
	data->infile = open(filepath, O_RDONLY);
	if (data->infile == -1)
	{
		ft_printf("Problem opening the %s.\n", filepath);
		return (1);
	}
	return (0);
}