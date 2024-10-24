/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:18:51 by ylai              #+#    #+#             */
/*   Updated: 2024/10/24 20:16:09 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char *cmd, char *raw_paths)
{
	char	**envs;
	char	*sub_path;
	char	*full_path;
	int		i;

	envs = ft_split((raw_paths) + 5, ':');
	i = 0;
	while (envs[i])
	{
		sub_path = ft_strjoin("/", cmd);
		full_path = ft_strjoin(envs[i], sub_path);
		free(sub_path);
		if (!access(full_path, F_OK | R_OK | X_OK))
			break ;
		free(full_path);
		full_path = NULL;
		i++;
	}
	free_things(envs);
	if (!full_path)
		return (cmd);
	return (full_path);
}
