/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:55:01 by ylai              #+#    #+#             */
/*   Updated: 2024/09/08 18:12:40 by ylai             ###   ########.fr       */
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
	pid_t	pid1;
	pid_t	pid2;
	int		pipefd[2];
	int	infile;
	int	outfile;
	char	*cmd1;
	char	*cmd2;
	char	**cmd_f_sp1;
	char	**cmd_f_sp2;
}						t_data;

extern char *paths[];

char	*ft_strnstr(const char *big, const char *little, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);
int		ft_printf(const char *str, ...);
int		open_file(char *filepath, t_data *data);
int		check_cmd(char *cmd1, char *cmd2, t_data *data);
int		create_pipe(t_data *data);
int		check_fork(pid_t pid);
int		num_arg(int argc);
int		pipey(pid_t pid, int close_pfd, int use_pfd, int infile, char *cmd, char **cmd_f_sp);
void  check_outfile(char *filepath, t_data *data);

#endif