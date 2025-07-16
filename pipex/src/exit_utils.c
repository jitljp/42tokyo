/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:47:52 by mjeremy           #+#    #+#             */
/*   Updated: 2025/07/16 12:01:25 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	exit_message(int code, char *msg)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	exit(code);
}

void	perror_exit(int code, char *cause, pid_t wait_pid)
{
	if (wait_pid > 0)
		waitpid(wait_pid, NULL, 0);
	ft_putstr_fd("bash: ", STDERR_FILENO);
	perror(cause);
	exit(code);
}

void	path_exit(int code, char *cmd, char **env, pid_t wait_pid)
{
	int	i;
	int	has_slash;

	if (wait_pid > 0)
		waitpid(wait_pid, NULL, 0);
	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	has_slash = (ft_strchr(cmd, '/') != NULL);
	if (!env[i] || has_slash)
	{
		ft_putstr_fd("bash: ", STDERR_FILENO);
		ft_putstr_fd(cmd, STDERR_FILENO);
		ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
	}
	else
	{
		ft_putstr_fd(cmd, STDERR_FILENO);
		ft_putstr_fd(": command not found\n", STDERR_FILENO);
	}
	free(cmd);
	exit(code);
}

void	exec_exit(char **cmd_split, char *path, pid_t wait_pid)
{
	char	*dup;

	if (wait_pid > 0)
		waitpid(wait_pid, NULL, 0);
	dup = ft_strdup(path);
	free_split(cmd_split);
	ft_putstr_fd("bash: ", STDERR_FILENO);
	perror(dup);
	free(dup);
	exit(127);
}
