#include "pipex.h"

int	check_full(char *cmd)
{
	int i;
	int	len;
	char	*str;

	i = 0;
	while (paths[i] != NULL)
	{
		len = ft_strlen(paths[i]);
		str = ft_strnstr(cmd, paths[i], len);
		if (str != NULL)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	set_path(char ***cmd_f_sp, char **cmd)
{
	int	i;
	char	*full_path;

	i = 0;
	while (paths[i] != NULL && *cmd == NULL)
	{
		full_path = ft_strjoin(paths[i], *cmd_f_sp[0]);
		ft_printf("*cmd_f_sp[0]: %s\n", *cmd_f_sp[0]);
		if (access(full_path, X_OK) == 0)
		{

		ft_printf("full_path: %s\n", full_path);
			*cmd = full_path;
			*cmd_f_sp[0] = full_path;
		}
		i++;
		ft_printf("i: %d\n", i);
	}
	// free(full_path);
	if (*cmd == NULL)
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
	{
		ft_printf("Either of the cmd is NULL\n");
		return (1);
	}
	space_str = ft_strdup(" ");
	cmd_f_sp1 = ft_split(cmd1, *space_str);
	cmd_f_sp2 = ft_split(cmd2, *space_str);
	ft_printf("in check_cmd\n");
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
	ft_printf("data->cmd_f_sp1: %s\n", data->cmd_f_sp1[0]);
	set_path1 = set_path(&(data->cmd_f_sp1), &(data->cmd1));
	set_path2 = set_path(&(data->cmd_f_sp2), &(data->cmd2));
	
	// free(cmd_f_sp1);
	// free(cmd_f_sp2);
	ft_printf("data->cmd_f_sp2[0]: %s\n\n", data->cmd_f_sp2[0]);
	ft_printf("data->cmd_f_sp2[1]: %s\n\n", data->cmd_f_sp2[1]);
	free(space_str);
	if (set_path1 == 0 || set_path2 == 0)
	{
		perror("access");
		ft_printf("Command not found\n");
		return (1);
	}
	return (0);
}
