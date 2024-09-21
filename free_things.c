#include "pipex.h"

void  free_things(t_data *data)
{
  free(data->cmd_f_sp1[0]);
  free(data->cmd_f_sp2[0]);
  free(data->cmd_f_sp1[1]);
  free(data->cmd_f_sp2[1]);

  free(data->cmd_f_sp1[2]);
  free(data->cmd_f_sp2[2]);
  free(data->cmd_f_sp1);
  free(data->cmd_f_sp2);
}