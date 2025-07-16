/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 12:46:18 by mjeremy           #+#    #+#             */
/*   Updated: 2025/07/16 18:11:34 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static void	execute_cmd(char **cmd, char **env, pid_t pid)
{
	char	*path;
	char	*cause;

	if (ft_strchr(cmd[0], '/'))
		path = cmd[0];
	else
		path = get_cmd_path(cmd[0], env);
	if (!path)
	{
		cause = ft_strdup(cmd[0]);
		free_split(cmd);
		path_exit(127, cause, env, pid);
	}
	execve(path, cmd, env);
	exec_exit(cmd, path, pid);
}

static void	process1(int *fd, char **argv, char **env, pid_t pid)
{
	int		infile;
	char	**cmd;

	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
		perror_exit(1, argv[1], pid);
	if (is_empty_cmd(argv[2], env, infile, pid))
		return ;
	cmd = ft_split(argv[2], ' ');
	setup_fds(infile, fd[1], fd);
	execute_cmd(cmd, env, pid);
}

static void	process2(int *fd, char **argv, char **env, pid_t pid)
{
	int		outfile;
	char	**cmd;

	outfile = open(argv[4], O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (outfile < 0)
		perror_exit(1, argv[4], pid);
	if (is_empty_cmd(argv[3], env, outfile, pid))
		return ;
	cmd = ft_split(argv[3], ' ');
	setup_fds(fd[0], outfile, fd);
	execute_cmd(cmd, env, pid);
}

int	main(int argc, char **argv, char **env)
{
	pid_t	pid;
	int		fd[2];

	if (argc != 5)
		exit_message(1, "Usage: ./pipex infile cmd1 cmd2 outfile\n");
	if (pipe(fd) == -1)
		exit_message(1, "pipe error\n");
	pid = fork();
	if (pid == -1)
		exit_message(1, "fork error\n");
	if (pid == 0)
		process1(fd, argv, env, pid);
	process2(fd, argv, env, pid);
	return (0);
}
