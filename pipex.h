/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:55:01 by ylai              #+#    #+#             */
/*   Updated: 2024/10/24 20:29:14 by ylai             ###   ########.fr       */
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

typedef struct s_data
{
	char	**paths;
	int		pipefd[2];
	int		infile;
	int		outfile;
}						t_data;

char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_printf(const char *str, ...);
void	open_file(char *in_filepath, char *out_filepath, t_data *data);
int		create_pipe(t_data *data);
int		check_fork(pid_t pid);
int		num_arg(int argc);
void	free_things(char **av);
void	pipey(t_data *data, int key);
char	*get_path(char *cmd, char *raw_paths);
pid_t	forking(t_data *data, char **envp, char *argv, int key);

#endif