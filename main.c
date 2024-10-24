/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:38:36 by ylai              #+#    #+#             */
/*   Updated: 2024/10/24 19:25:50 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	execute(char *argv, char **envp)
{
	char	*path;
	char	**av;
	int		status;
	int		i;
	
	av = ft_split(argv, ' ');
	status = -1;
	if (!av)
		return (status);
	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (ft_strncmp(av[0], "./", 2))
		path = get_path(av[0], envp[i]);
	else
		path = av[0];
	status = execve(path, av, envp);
	if (path != av[0])
		free(path);
	i = 0;
	while (av[i])
		free(av[i++]);
	free(av);
	return (status);
}

pid_t	forking(t_data *data, char **envp, char *argv, int key)
{
	pid_t	pid;

	pid = fork();
	if (check_fork(pid))
	{
		// free_things(data);
		exit(1);
	}
	if (pid == 0)
	{
		pipey(data, key);
		if (execute(argv, envp) == -1)
		{
			perror("Command not found");
			if (errno == EACCES)
				exit(126);
			exit(127);
		}
		exit(0);
	}
	return (pid);
}

int	main(int ac, char **argv, char **envp)
{
	t_data	data;
	// int	pipefd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		status;
	
	status = 1;
	// envp = NULL;
	// ft_memset(&data, 0, sizeof(t_data));
	if (num_arg(ac)) 
		return (1);
	open_file(argv[1], argv[4], &data);
	if (create_pipe(&data))
		return (1);
	pid1 = forking(&data, envp, argv[2], 1);
	pid2 = forking(&data, envp, argv[3], 0);
	
	// initialize_paths(&data, envp);
	// fake_paths(&data);
	// int i = 0;
	// while (data.fake_paths[i] != NULL)
	// {
	// 	ft_printf("%s\n", data.fake_paths[i]);
	// 	i++;
	// }
	// if (check_cmd(argv[2], argv[3], &data))
	// {
	// 	free_things(&data);
	// 	return (0);
	// }
	// data.pid1 = fork();
	// if (check_fork(data.pid1) == 0 && data.pid1 == 0)
	// {
	// 	close(pipefd[0]);
	// 		ft_printf("did i free things?\n");
	// 	if (pipey(&(pipefd[1]), &(data.infile), data.cmd1, data.cmd_f_sp1, 1))
	// 	{
	// 		free_things(&data);
	// 		return (0);
	// 	}
	// }
	// else if (check_fork(data.pid1) == 1)
	// {
	// 	free_things(&data);
	// 	return (0);
	// }
	// data.pid2 = fork();
	// if (check_fork(data.pid2) == 0 && data.pid2 == 0)
	// {
	// 	close(pipefd[1]);
	// 	if (pipey(&(pipefd[0]), &(data.outfile), data.cmd2, data.cmd_f_sp2, 2))
	// 	{
	// 		ft_printf("safsa");
	// 		free_things(&data);
	// 		return (0);
	// 	}
	// }
	// else if (check_fork(data.pid2) == 1)
	// {
	// 	free_things(&data);
	// 	return (0);
	// }
	close(data.infile);
	close(data.outfile);
	close(data.pipefd[0]);
	close(data.pipefd[1]);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
	return (WEXITSTATUS(status));
}