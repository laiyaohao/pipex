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

int open_file(char *in_filepath, char *out_filepath, t_data *data)
{
	data->infile = open(in_filepath, O_RDONLY);
	if (data->infile == -1)
	{
		ft_printf("Problem opening the %s.\n", in_filepath);
		return (1);
	}
	data->outfile = open(out_filepath, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->outfile == -1)
	{
		ft_printf("Problem opening the %s.\n", out_filepath);
		return (1);
	}
	return (0);
}