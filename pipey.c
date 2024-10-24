/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipey.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:11:14 by ylai              #+#    #+#             */
/*   Updated: 2024/10/24 17:14:15 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipey(t_data *data, int key)
{
	int	status1;
	int	status2;

	if (key == 1)
	{
		status1 = dup2(data->pipefd[1], STDOUT_FILENO);
		status2 = dup2(data->infile, STDIN_FILENO);
	}
	else
	{
		status1 = dup2(data->pipefd[0], STDIN_FILENO);
		status2 = dup2(data->outfile, STDOUT_FILENO);
	}
	close(data->pipefd[0]);
	close(data->pipefd[1]);
	close(data->infile);
	close(data->outfile);
	// if (execve(cmd, cmd_f_sp, NULL) == -1)
	// {
	// 	perror("execve");
	// 	return (1);
	// }
	if (status1 == -1 || status2 == -1)
		exit(1);
}