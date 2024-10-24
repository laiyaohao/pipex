/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipey.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:11:14 by ylai              #+#    #+#             */
/*   Updated: 2024/10/03 20:44:57 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipey(int *use_pfd, int *infile, char *cmd, char **cmd_f_sp, int key)
{
	int	status1;
	int	status2;

	if (key == 1)
	{
		status1 = dup2(*use_pfd, STDOUT_FILENO);
		status2 = dup2(*infile, STDIN_FILENO);
	}
	else
	{
		status1 = dup2(*use_pfd, STDIN_FILENO);
		status2 = dup2(*infile, STDOUT_FILENO);
	}
	close(*use_pfd);
	close(*infile);
	// if (execve(cmd, cmd_f_sp, NULL) == -1)
	// {
	// 	perror("execve");
	// 	return (1);
	// }
	if (status1 == -1 || status2 == -1)
		exit(1);
	return (0);
}