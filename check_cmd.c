/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 19:06:29 by ylai              #+#    #+#             */
/*   Updated: 2024/10/04 17:08:30 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		// ft_printf("now inside check_full\n");
		if (str != NULL)
			return (1);
		i++;
	}
	return (0);
}

void	set_path(char **paths, char ***cmd_f_sp, char **cmd)
{
	int	i;
	char	*full_path;
	char	*tmp;
	char	*slash;

	i = 0;
	slash = ft_strdup("/");
	full_path = NULL;
	tmp = NULL;
	while (paths != NULL && paths[i] != NULL && *cmd == NULL)
	{
		free(tmp);
		free(full_path);
		tmp = ft_strjoin(paths[i], slash);
		full_path = ft_strjoin(tmp, *cmd_f_sp[0]);
		if (access(full_path, X_OK) == 0)
		{
			*cmd = full_path;
			free(*cmd_f_sp[0]);
			*cmd_f_sp[0] = full_path;
			break;
		}
		i++;
	}
	if (*cmd == NULL)
	{
		
		*cmd = *cmd_f_sp[0];
		ft_printf("cmd is %s\n", *cmd);
	}
	free(tmp);
	free(slash);
}

int	check_cmd(char *cmd1, char *cmd2, t_data *data)
{
	if (cmd1 == NULL || cmd2 == NULL || *cmd1 == '\0' || *cmd2 == '\0')
	{
		ft_printf("Either of the cmd is NULL\n");
		return (1);
	}
	data->cmd_f_sp1 = ft_split(cmd1, ' ');
	data->cmd_f_sp2 = ft_split(cmd2, ' ');
	// ft_printf("inside check_cmd\n");
	if (check_full(data->paths, data->cmd_f_sp1[0]))
	{
		data->cmd1 = data->cmd_f_sp1[0];
		// ft_printf("inside here 1\n");
	}
	else
		set_path(data->paths, &(data->cmd_f_sp1), &(data->cmd1));
	if (check_full(data->paths, data->cmd_f_sp2[0]))
	{
		// ft_printf("inside here 2\n");
		data->cmd2 = data->cmd_f_sp2[0];
	}
	else
		set_path(data->paths, &(data->cmd_f_sp2), &(data->cmd2));
	return (0);
}
