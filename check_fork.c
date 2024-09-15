#include "pipex.h"

int check_fork(pid_t pid)
{
  if (pid == -1)
	{
		perror("fork");
		return (1);
	}
  return (0);
}
