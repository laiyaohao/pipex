#include "pipex.h"

int	check_full(char *cmd)
{
	int i;

	i = 0;
	while (paths[i] != NULL)
	{
		if (ft_strnstr(cmd, paths[i], ft_strlen(paths[i])) != '\0')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	set_path(char *cmd1, char *cmd2, t_data *data)
{
	int	i;
	char	*full_path1;
	char	*full_path2;

	i = 0;
	while (paths[i] != NULL && data->cmd1 != NULL)
	{
		full_path1 = ft_strjoin(paths[i], cmd1);
		if (access(full_path1, X_OK))
			data->cmd1 = full_path1;
		i++;
	}
	i = 0;
	while (paths[i] != NULL && data->cmd2 != NULL)
	{
		full_path2 = ft_strjoin(paths[i], cmd2);
		if (access(full_path2, X_OK))
			data->cmd2 = full_path2;
		i++;
	}
	free(full_path1);
	free(full_path2);
	if (data->cmd1 == NULL || data->cmd2 == NULL)
		return (0);
	return (1);
}

int	check_cmd(char *cmd1, char *cmd2, t_data *data)
{
	char	**full_path1;
	char	**full_path2;

	if (cmd1 == NULL || cmd2 == NULL)
		return (1);
	full_path1 = ft_split(cmd1, " ");
	full_path2 = ft_split(cmd2, " ");
	if (check_full(cmd1))
		data->cmd1 = cmd1;
	if (check_full(cmd2))
		data->cmd2 = cmd2;
	if (set_path(cmd1, cmd2, data) == 0)
	{
		perror("access");
		ft_printf("Command not found\n");
		return (1);
	}
	return (0);
}
