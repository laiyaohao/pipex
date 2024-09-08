#include "pipex.h"

void	execute_first(pid_t *pid1)
{
	if (*pid1 == 0)
	{
		if (dup2(fd[0], STDIN_FILENO) == -1)
			return ;
		close(fd[0]);
		close(fd[1]);
		if (execve(cmd1, NULL, NULL) == -1)
			return ;
	}
}