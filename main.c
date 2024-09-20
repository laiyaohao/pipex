/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:38:36 by ylai              #+#    #+#             */
/*   Updated: 2024/09/08 19:53:54 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int	pipefd[2];
	
	data.cmd1 = NULL;
	data.cmd2 = NULL;
	if (num_arg(argc) || open_file(argv[1], &data) || create_pipe(&pipefd) || \
	check_cmd(argv[2], argv[3], &data))
		return (1);
	data.pid1 = fork();
	if (check_fork(data.pid1) || \
	pipey(&(data.pid1), &(pipefd[0]), &(pipefd[1]), &(data.infile), data.cmd1, data.cmd_f_sp1, 1))
		return (1);
	check_outfile(argv[4], &data);
	data.pid2 = fork();
	
	if (pipey(&(data.pid2), &(pipefd[1]), &(pipefd[0]), &(data.outfile), data.cmd2, data.cmd_f_sp2, 2))
		return (1);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(data.pid1, NULL, 0);
	waitpid(data.pid2, NULL, 0);
	// int i = 0;
	// while (envp[i] != NULL)
	// {
	// 	printf("%s\n", envp[i]);
	// 	i++;
	// }
	return (0);
	// execve(argv[1], &argv[1], NULL);
	// char *filepath = "/bin/echo";
	// char *argv[] = { filepath, "Hello World", NULL };

	// execve (filepath, argv, NULL);
}