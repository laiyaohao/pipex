#include "pipex.h"

int open_file(char *filepath, t_data *data)
{
	if (access(filepath, F_OK) == -1)
		return (1);
	data->infile = open(filepath, O_RDONLY);
	if (data->infile == -1)
	{
		perror("open");
		return (1);
	}
	return (0);
}