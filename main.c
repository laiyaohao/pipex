/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:38:36 by ylai              #+#    #+#             */
/*   Updated: 2024/09/02 19:12:04 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	char	*cmd1;
	char	*cmd2;
	
	if (argc != 5)
	{
		ft_printf("Wrong number of arguments\n");
		return (1);
	}
	cmd1 = argv[2];
	cmd2 = argv[3];
	if (pipex(cmd1, cmd2, argv[1]))
		return (1);
	return (0);
}