/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 12:46:06 by mjeremy           #+#    #+#             */
/*   Updated: 2025/07/20 11:24:33 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/*
Checks if the command string is empty (contains only spaces).

- Skips leading spaces in the command.
- If the command is effectively empty, duplicates it for error reporting,
  closes the provided file descriptor if valid,
   and exits via path_exit with code 127.
- Returns 0 if the command is not empty.
*/
int	is_empty_cmd(char *cmd, int fd_to_close, pid_t pid)
{
	int		i;
	char	*cause;

	(void)pid;
	i = 0;
	while (cmd[i] == ' ')
		i++;
	if (cmd[i] == '\0')
	{
		cause = ft_strdup(cmd);
		close(fd_to_close);
		free(cause);
		exit(127);
	}
	return (0);
}

/*
Sets up file descriptors for input and output redirection and closes pipe ends.

- Duplicates fd_in to STDIN_FILENO.
- Duplicates fd_out to STDOUT_FILENO.
- Closes both ends of the pipe to prevent leaks.
*/
void	setup_fds(int fd_in, int fd_out, int *pipe_fd)
{
	dup2(fd_in, STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
}

/*
Joins a directory path and a command name with a slash to form a full path.

- Allocates and returns a new string in the format "dir/cmd".
- Frees intermediate temporary string.
*/
static char	*join_cmd(char *dir, char *cmd)
{
	char	*tmp;
	char	*full;

	tmp = ft_strjoin(dir, "/");
	full = ft_strjoin(tmp, cmd);
	free(tmp);
	return (full);
}

/*
Searches for the executable path of a command
using the PATH environment variable.

- Locates the PATH entry in env.
- Splits PATH into directories.
- For each directory, constructs full path
   and checks executability with access(X_OK).
- Returns the first valid full path found, freeing splits along the way.
- Returns NULL if no executable path is found.
*/
char	*get_cmd_path(char *cmd, char **env)
{
	int		i;
	char	**paths;
	char	*full;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (!env[i])
		return (NULL);
	paths = ft_split(env[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		full = join_cmd(paths[i], cmd);
		if (access(full, X_OK) == 0)
		{
			free_split(paths);
			return (full);
		}
		free(full);
		i++;
	}
	free_split(paths);
	return (NULL);
}

/*
Frees a null-terminated array of strings.

- Iterates through each string in the array and frees it.
- Frees the array pointer itself.
*/
void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
