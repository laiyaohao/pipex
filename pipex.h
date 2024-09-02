/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:55:01 by ylai              #+#    #+#             */
/*   Updated: 2024/09/02 19:11:54 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <errno.h>
# include <string.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int		ft_printf(const char *str, ...);
int		pipex(char *cmd1, char *cmd2, char *argv);

#endif