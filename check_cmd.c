#include "pipex.h"

int	check_full(char *cmd)
{
	int i;

	i = 0;
	while (paths[i] != NULL)
	{
		if (*ft_strnstr(cmd, paths[i], ft_strlen(paths[i])) != '\0')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	set_path(char **cmd_f_sp, char *cmd)
{
	int	i;
	char	*full_path;

	i = 0;
	while (paths[i] != NULL && cmd == NULL)
	{
		full_path = ft_strjoin(paths[i], cmd_f_sp[0]);
		if (access(full_path, X_OK))
		{
			cmd = full_path;
			cmd_f_sp[0] = full_path;
		}
		i++;
	}
	free(full_path);
	if (cmd == NULL)
		return (0);
	return (1);
}

int	check_cmd(char *cmd1, char *cmd2, t_data *data)
{
	char	**cmd_f_sp1;
	char	**cmd_f_sp2;
	int	set_path1;
	int	set_path2;
	char	*space_str;

	if (cmd1 == NULL || cmd2 == NULL || *cmd1 == '\0' || *cmd2 == '\0')
		return (1);
	space_str = ft_strdup(" ");
	cmd_f_sp1 = ft_split(cmd1, *space_str);
	cmd_f_sp2 = ft_split(cmd2, *space_str);
	if (check_full(cmd_f_sp1[0]))
	{	
		data->cmd1 = cmd_f_sp1[0];
		data->cmd_f_sp1 = cmd_f_sp1;
	}
	if (check_full(cmd_f_sp2[0]))
	{
		data->cmd2 = cmd_f_sp2[0];
		data->cmd_f_sp2 = cmd_f_sp2;
	}
	data->cmd_f_sp1 = cmd_f_sp1;
	data->cmd_f_sp2 = cmd_f_sp2;
	set_path1 = set_path(data->cmd_f_sp1, data->cmd1);
	set_path2 = set_path(data->cmd_f_sp2, data->cmd2);
	free(cmd_f_sp1);
	free(cmd_f_sp2);
	free(space_str);
	if (set_path1 == 0 || set_path2 == 0)
	{
		perror("access");
		ft_printf("Command not found\n");
		return (1);
	}
	return (0);
}
