/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_outfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 19:06:21 by ylai              #+#    #+#             */
/*   Updated: 2024/10/03 20:50:43 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void  check_outfile(char *filepath, t_data *data)
{
  int outf_fd;

  if (access(filepath, F_OK) == -1)
  {
    data->outfile = open(filepath, O_WRONLY | O_CREAT | O_TRUNC, 0644);
  }
  else
  {
    outf_fd = open(filepath, O_WRONLY | O_TRUNC, 0644);
    if (outf_fd < 0)
    {
      perror("Error opening outfile");
      exit(EXIT_FAILURE);
    }
    else
      data->outfile = outf_fd;
  }
}