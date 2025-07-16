/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 12:46:06 by mjeremy           #+#    #+#             */
/*   Updated: 2025/07/16 12:01:27 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	wrap_up(pid_t pid, int	*fd)
{
	int	status;

	close(fd[0]);
	close(fd[1]);
	waitpid(pid, &status, 0);
	exit(WEXITSTATUS(status));
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
