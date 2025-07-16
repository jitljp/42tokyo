/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 12:46:06 by mjeremy           #+#    #+#             */
/*   Updated: 2025/07/16 16:46:24 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	is_empty_cmd(char *cmd, char **env, int fd_to_close, pid_t pid)
{
	int		i;
	char	*cause;

	i = 0;
	while (cmd[i] == ' ')
		i++;
	if (cmd[i] == '\0')
	{
		cause = ft_strdup("");
		if (fd_to_close >= 0)
			close(fd_to_close);
		path_exit(127, cause, env, pid);
	}
	return (0);
}

void	setup_fds(int fd_in, int fd_out, int *pipe_fd)
{
	dup2(fd_in, STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
}

static char	*join_cmd(char *dir, char *cmd)
{
	char	*tmp;
	char	*full;

	tmp = ft_strjoin(dir, "/");
	full = ft_strjoin(tmp, cmd);
	free(tmp);
	return (full);
}

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
