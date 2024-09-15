#include "pipex.h"

void  check_outfile(char *filepath, t_data *data)
{
  int outf_fd;

  // filepath does not exist; create a new file
  if (access(filepath, F_OK) == -1)
  {
    data->outfile = open(filepath, O_WRONLY | O_CREAT | O_TRUNC, 0644);
  }
  // filepath exist
  else
  {
    outf_fd = open(filepath, O_WRONLY | O_TRUNC), 0644;
    if (outf_fd < 0)
    {
      perror("Error opening outfile");
      exit(EXIT_FAILURE);
    }
    else
      data->outfile = outf_fd;
  }
}