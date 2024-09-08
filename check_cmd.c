#include "pipex.h"

int	check_cmd(char *cmd1, char *cmd2)
{
	if (access(cmd1, X_OK) == -1 || access(cmd2, X_OK) == -1)
	{
		ft_printf("Command not found\n");
		return (1);
	}
	return (0);
}
