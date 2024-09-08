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

	if (num_arg(argc) || open_file(argv[1], &data) || create_pipe(data) || \
	check_cmd(argv[2], argv[3]))
		return (1);
	data.pid1 = fork();
	if (pipex(data.pid1, data.pipefd[0], data.pipefd[1], data.infile))
		return (1);
	data.pid2 = fork();
	if (pipex(data.pid2, fd[1], fd[0], argv))
		return (1);
	waitpid(data.pid1, NULL, 0);
	waitpid(data.pid2, NULL, 0);
	return (0);
	// execve(argv[1], &argv[1], NULL);
	// char *filepath = "/bin/echo";
	// char *argv[] = { filepath, "Hello World", NULL };

	// execve (filepath, argv, NULL);
}