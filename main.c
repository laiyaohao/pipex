/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:38:36 by ylai              #+#    #+#             */
/*   Updated: 2024/10/24 19:56:40 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **argv, char **envp)
{
	t_data	data;
	pid_t	pid1;
	pid_t	pid2;
	int		status;

	status = 1;
	if (num_arg(ac))
		return (1);
	open_file(argv[1], argv[4], &data);
	if (create_pipe(&data))
		return (1);
	pid1 = forking(&data, envp, argv[2], 1);
	pid2 = forking(&data, envp, argv[3], 0);
	close(data.infile);
	close(data.outfile);
	close(data.pipefd[0]);
	close(data.pipefd[1]);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
	return (WEXITSTATUS(status));
}
