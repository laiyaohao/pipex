#include "pipex.h"

int	create_pipe(int (*pipefd)[])
{
	if (pipe(*pipefd) == -1)
	{
		perror("pipe");
		return (1);
	}
	return (0);
}