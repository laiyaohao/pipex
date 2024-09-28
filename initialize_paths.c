#include "pipex.h"

// char  *paths[] = {
//   "/usr/bin/",
//   "/usr/sbin/",
//   "/bin/",
//   "/sbin/",
//   "/usr/local/sbin/",
//   "/usr/local/bin/",
//   NULL,
// };

// char	*paths[] = getenv("PATH");

void	initialize_paths(t_data *data, char **envp)
{
	char	*raw_paths;
	int	i;

	i = 0;
	while (envp != NULL && envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			raw_paths = envp[i] + 5;
			break ;
		}
		i++;
	}
	data->paths = ft_split(raw_paths, ':');

	// data->paths = ft_split(raw_paths, ':');
}
