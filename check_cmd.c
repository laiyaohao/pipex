#include "pipex.h"

int	check_full(char **paths, char *cmd)
{
	int i;
	int	len;
	char	*str;

	i = 0;
	while (paths != NULL && paths[i] != NULL)
	{
		len = ft_strlen(paths[i]);
		str = ft_strnstr(cmd, paths[i], len);
		if (str != NULL)
		{
			return (1);
		}
		i++;
	}
		// ft_printf("i: %i\n", i);
	return (0);
}

int	set_path(char **paths, char ***cmd_f_sp, char **cmd)
{
	int	i;
	char	*full_path;
	char	*tmp = NULL;
	char	*slash = NULL;

	i = 0;
	slash = ft_strdup("/");
	while (paths != NULL && paths[i] != NULL && *cmd == NULL)
	{
		free(tmp);
		free(full_path);
		tmp = ft_strjoin(paths[i], slash);
		full_path = ft_strjoin(tmp, *cmd_f_sp[0]);
		ft_printf("*cmd_f_sp[0]: %s\n", *cmd_f_sp[0]);
		ft_printf("full_path: %s\n", full_path);
		if (access(full_path, X_OK) == 0)
		{

			ft_printf("can access\n");
			*cmd = full_path;
			free(*cmd_f_sp[0]);
			*cmd_f_sp[0] = full_path;
			break;
		}
		i++;
		ft_printf("i: %d\n", i);
	}
	free(tmp);
	free(slash);
	if (*cmd == NULL)
		return (0);
	return (1);
}

int	check_cmd(char *cmd1, char *cmd2, t_data *data)
{
	// char	**cmd_f_sp1;
	// char	**cmd_f_sp2;
	int	set_path1;
	int	set_path2;

	set_path1 = 1;
	set_path2 = 1;
	if (cmd1 == NULL || cmd2 == NULL || *cmd1 == '\0' || *cmd2 == '\0')
	{
		ft_printf("Either of the cmd is NULL\n");
		return (1);
	}
	
	data->cmd_f_sp1 = ft_split(cmd1, ' ');
	data->cmd_f_sp2 = ft_split(cmd2, ' ');
	ft_printf("in check_cmd\n");
	if (check_full(data->paths, data->cmd_f_sp1[0]))
		data->cmd1 = data->cmd_f_sp1[0];
	else
		set_path1 = set_path(data->paths, &(data->cmd_f_sp1), &(data->cmd1));
	if (check_full(data->paths, data->cmd_f_sp2[0]))
		data->cmd2 = data->cmd_f_sp2[0];
	else
		set_path2 = set_path(data->paths, &(data->cmd_f_sp2), &(data->cmd2));
	// data->cmd_f_sp1 = cmd_f_sp1;
	// data->cmd_f_sp2 = cmd_f_sp2;
	ft_printf("data->cmd_f_sp1: %s\n", data->cmd_f_sp1[0]);
	// set_path1 = set_path(&(data->cmd_f_sp1), &(data->cmd1));
	// set_path2 = set_path(&(data->cmd_f_sp2), &(data->cmd2));
	
	// free(cmd_f_sp1);
	// free(cmd_f_sp2);
	ft_printf("data->cmd_f_sp2[0]: %s\n\n", data->cmd_f_sp2[0]);
	ft_printf("data->cmd_f_sp2[1]: %s\n\n", data->cmd_f_sp2[1]);
	// if (set_path1 == 0 || set_path2 == 0)
	// {
	// 	perror("access");
	// 	ft_printf("Command not found\n");
	// 	return (1);
	// }
	return (0);
}
