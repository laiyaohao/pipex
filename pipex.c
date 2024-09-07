/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:11:14 by ylai              #+#    #+#             */
/*   Updated: 2024/09/07 17:29:20 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex(char *cmd1, char *cmd2, char *argv)
{
	// open the file and get the contents
	int	fd[2];

	if (pipe(fd) == -1)
		return (1);
	if (fork() == 0)
	{
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			return (1);
		close(fd[0]);
		close(fd[1]);
		if (execve(cmd1, NULL, NULL) == -1)
			return (1);
	}
	else
	{
		if (fork() == 0)
		{
			if (dup2(fd[0], STDIN_FILENO) == -1)
				return (1);
			close(fd[0]);
			close(fd[1]);
			if (execve(cmd2, NULL, NULL) == -1)
				return (1);
		}
		else
		{
			close(fd[0]);
			close(fd[1]);
			wait(NULL);
			wait(NULL);
		}
	}
	return (0);
	
}