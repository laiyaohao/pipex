#include "pipex.h"

void  free_things(t_data *data)
{
	int	i;

	i = 1;
	free(data->cmd1);
	free(data->cmd2);
	while (data->cmd_f_sp1[i] != NULL)
	{
		free(data->cmd_f_sp1[i]);
		i++;
	}
	i = 1;
	while (data->cmd_f_sp2[i] != NULL)
	{
		free(data->cmd_f_sp2[i]);
		i++;
	}
	free(data->cmd_f_sp1);
	free(data->cmd_f_sp2);
	
  // free(data->cmd_f_sp1[0]);
  // free(data->cmd_f_sp2[0]);
  // free(data->cmd_f_sp1[1]);
  // free(data->cmd_f_sp2[1]);

  // free(data->cmd_f_sp1[2]);
  // free(data->cmd_f_sp2[2]);
  // free(data->cmd_f_sp1);
  // free(data->cmd_f_sp2);
}