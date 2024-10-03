/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_things.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 19:06:08 by ylai              #+#    #+#             */
/*   Updated: 2024/10/03 20:46:50 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void  free_things(t_data *data)
{
	int	i;

	i = 1;
	free(data->cmd1);
	free(data->cmd2);
	while (data->cmd_f_sp1 != NULL && data->cmd_f_sp1[i] != NULL)
	{
		free(data->cmd_f_sp1[i]);
		i++;
	}
	i = 1;
	while (data->cmd_f_sp2 != NULL && data->cmd_f_sp2[i] != NULL)
	{
		free(data->cmd_f_sp2[i]);
		i++;
	}
	free(data->cmd_f_sp1);
	free(data->cmd_f_sp2);
	i = 0;
	while (data->paths != NULL && data->paths[i] != NULL)
	{
		free(data->paths[i]);
		i++;
	}
	free(data->paths);
}