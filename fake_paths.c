#include "pipex.h"

void	fake_paths(t_data *data)
{
	data->fake_paths[0] = "/usr/bin/";
	data->fake_paths[1] = "/usr/sbin/";
	data->fake_paths[2] = "/bin/";
	data->fake_paths[3] = "/sbin/";
	data->fake_paths[4] = "/usr/local/sbin/";
	data->fake_paths[5] = "/usr/local/bin/";
	data->fake_paths[6] = NULL;
}