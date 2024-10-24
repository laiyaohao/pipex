/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:18:51 by ylai              #+#    #+#             */
/*   Updated: 2024/10/24 16:18:52 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char *cmd, char *raw_paths)
{
	char	**paths;
	char	*s_path;
	char	*path;
	int		i;

	paths = ft_split((raw_paths) + 5, ':');
	i = 0;
	while (paths[i])
	{
		s_path = ft_strjoin("/", cmd);
		path = ft_strjoin(paths[i], s_path);
		free(s_path);
		if (!access(path, F_OK | R_OK | X_OK))
			break ;
		free(path);
		path = NULL;
		i++;
	}
	i = 0;
	while (paths[i])
		free(paths[i++]);
	free(paths);
	if (!path)
		return (cmd);
	return (path);
}
