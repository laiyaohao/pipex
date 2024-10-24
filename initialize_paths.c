/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_paths.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 20:48:52 by ylai              #+#    #+#             */
/*   Updated: 2024/10/03 20:48:53 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*initialize_paths(char **envp)
{
	char	*raw_paths;
	char	**paths;
	int	i;

	i = 0;
	raw_paths = NULL;
	while (envp != NULL && envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			raw_paths = envp[i] + 5;
			break ;
		}
		i++;
	}
	// data->paths = ft_split(raw_paths, ':');
	// paths = ft_split(raw_paths, ':');
	return (raw_paths);
}
