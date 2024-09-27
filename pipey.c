/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:11:14 by ylai              #+#    #+#             */
/*   Updated: 2024/09/08 19:43:29 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipey(int *use_pfd, int *infile, char *cmd, char **cmd_f_sp, int key)
{
	
	
	// if (*pid == 0)
	// {
		// close(*close_pfd);
		ft_printf("cmd: %s\n", cmd);
		if (key == 1)
		{
			dup2(*use_pfd, STDOUT_FILENO);
			dup2(*infile, STDIN_FILENO);
		}
		else
		{
			dup2(*use_pfd, STDIN_FILENO);
			dup2(*infile, STDOUT_FILENO);
		}
		close(*use_pfd);
		// right now, cmd will look something like:
		// "ls -l"
		// need to split it into 2 parts
		// first, "ls"
		if (execve(cmd, cmd_f_sp, NULL) == -1)
			return (1);
		return (0);
	// }
	
	
	// if (fork() == 0)
	// {
	// 	if (dup2(fd[1], STDOUT_FILENO) == -1)
	// 		return (1);
	// 	close(fd[0]);
	// 	close(fd[1]);
	// 	if (execve(cmd1, NULL, NULL) == -1)
	// 		return (1);
	// }
	// else
	// {
	// 	if (fork() == 0)
	// 	{
	// 		if (dup2(fd[0], STDIN_FILENO) == -1)
	// 			return (1);
	// 		close(fd[0]);
	// 		close(fd[1]);
	// 		if (execve(cmd2, NULL, NULL) == -1)
	// 			return (1);
	// 	}
	// 	else
	// 	{
	// 		close(fd[0]);
	// 		close(fd[1]);
	// 		wait(NULL);
	// 		wait(NULL);
	// 	}
	// }
	// return (0);
	
}