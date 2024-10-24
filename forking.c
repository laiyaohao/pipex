/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 19:06:29 by ylai              #+#    #+#             */
/*   Updated: 2024/10/24 20:24:36 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	execute(char *argv, char **envp)
{
	char	*full_path;
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
		full_path = get_path(av[0], envp[i]);
	else
		full_path = av[0];
	status = execve(full_path, av, envp);
	if (full_path != av[0])
		free(full_path);
	free_things(av);
	return (status);
}

pid_t	forking(t_data *data, char **envp, char *argv, int key)
{
	pid_t	pid;

	pid = fork();
	if (check_fork(pid))
	{
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
