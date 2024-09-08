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

int	pipex(pid_t *pid, int to_close_fd, int to_use_fd, int infile, char *cmd1, char *cmd2)
{
	if (*pid == -1)
	{
		perror("fork");
		return (1);
	}
	close(to_close_fd);
	if (*pid == 0)
	{
		
		return (1);
	}
	
	
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
	return (0);
	
}