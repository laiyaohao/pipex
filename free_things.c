#include "pipex.h"

void  free_things(t_data *data)
{
	int	i;

	i = 1;
	free(data->cmd1);
	free(data->cmd2);
	while (data->cmd_f_sp1 != NULL && data->cmd_f_sp1[i] != NULL)
	{
		free(data->cmd_f_sp1[i]);
		i++;
	}
	i = 1;
	while (data->cmd_f_sp2 != NULL && data->cmd_f_sp2[i] != NULL)
	{
		free(data->cmd_f_sp2[i]);
		i++;
	}
	free(data->cmd_f_sp1);
	free(data->cmd_f_sp2);
	i = 0;
	while (data->paths != NULL && data->paths[i] != NULL)
	{
		free(data->paths[i]);
		i++;
	}
	free(data->paths);
	// ft_printf("finished freeing\n");
  // free(data->cmd_f_sp1[0]);
  // free(data->cmd_f_sp2[0]);
  // free(data->cmd_f_sp1[1]);
  // free(data->cmd_f_sp2[1]);

  // free(data->cmd_f_sp1[2]);
  // free(data->cmd_f_sp2[2]);
  // free(data->cmd_f_sp1);
  // free(data->cmd_f_sp2);
}