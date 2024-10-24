/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 19:06:42 by ylai              #+#    #+#             */
/*   Updated: 2024/10/24 19:49:08 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_file(char *in_filepath, char *out_filepath, t_data *data)
{
	data->infile = open(in_filepath, O_RDONLY);
	if (data->infile == -1)
	{
		perror("Problem opening the input file\n");
	}
	data->outfile = open(out_filepath, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->outfile == -1)
	{
		perror("Problem opening the ouput file\n");
	}
}
