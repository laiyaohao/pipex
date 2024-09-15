#include "pipex.h"

int	create_pipe(t_data *data)
{
	if (pipe(data->pipefd) == -1)
	{
		perror("pipe");
		return (1);
	}
	return (0);
}