/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:38:36 by ylai              #+#    #+#             */
/*   Updated: 2024/09/28 18:19:20 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	int	pipefd[2];
	
	envp=NULL;
	data.cmd1 = NULL;
	data.cmd2 = NULL;
	initialize_paths(&data, envp);
	if (num_arg(argc) || open_file(argv[1], &data) || create_pipe(&pipefd) || \
	check_cmd(argv[2], argv[3], &data))
		return (1);
	data.pid1 = fork();
	if (check_fork(data.pid1) == 0 && data.pid1 == 0)
	{
		close(pipefd[0]);
		ft_printf("inside the correct con 1\n");
		if (pipey(&(pipefd[1]), &(data.infile), data.cmd1, data.cmd_f_sp1, 1))
			return (1);
	}
	else if (check_fork(data.pid1) == 1)
		return (1);
	/*
	if (data.pid1 == 0 && (check_fork(data.pid1) || \
	pipey(&(pipefd[0]), &(pipefd[1]), &(data.infile), data.cmd1, data.cmd_f_sp1, 1)))
		return (1);
	*/
	check_outfile(argv[4], &data);
	data.pid2 = fork();
	if (check_fork(data.pid2) == 0 && data.pid2 == 0)
	{
		close(pipefd[1]);
		ft_printf("inside the correct con 2\n");
		if (pipey(&(pipefd[0]), &(data.outfile), data.cmd2, data.cmd_f_sp2, 2))
			return (1);
	}
	else if (check_fork(data.pid2) == 1)
		return (1);
	/*
	// if (data.pid2 == 0 && (check_fork(data.pid2) || \
	// pipey(&(pipefd[1]), &(pipefd[0]), &(data.outfile), data.cmd2, data.cmd_f_sp2, 2)))
	// 	return (1);
		*/
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(data.pid1, NULL, 0);
	waitpid(data.pid2, NULL, 0);
	free_things(&data);
	// int i = 0;
	// while (envp[i] != NULL)
	// {
	// 	if (strncmp(envp[i], "PATH=", 5) == 0)
	// 		printf("%s\n", envp[i]);
	// 	// printf("%s\n", envp[i]);
	// 	i++;
	// }
	return (0);
	// execve(argv[1], &argv[1], NULL);
	// char *filepath = "/bin/echo";
	// char *argv[] = { filepath, "Hello World", NULL };

	// execve (filepath, argv, NULL);
}