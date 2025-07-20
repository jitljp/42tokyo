/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_processes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 09:55:00 by mjeremy           #+#    #+#             */
/*   Updated: 2025/07/20 09:55:00 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/*
Creates the pipe and forks the first child process.
*/
void	create_first_child(int *fd, char **argv, char **env, pid_t *pid1)
{
	if (pipe(fd) == -1)
	{
		ft_putstr_fd("pipe error\n", STDERR_FILENO);
		exit(1);
	}
	*pid1 = fork();
	if (*pid1 == -1)
	{
		ft_putstr_fd("fork error\n", STDERR_FILENO);
		exit(1);
	}
	if (*pid1 == 0)
		process1(fd, argv, env);
}

/*
Creates the second child process and closes pipe ends.
*/
void	create_second_child(int *fd, char **argv, char **env, pid_t *pid2)
{
	*pid2 = fork();
	if (*pid2 == -1)
	{
		ft_putstr_fd("fork error\n", STDERR_FILENO);
		exit(1);
	}
	if (*pid2 == 0)
		process2(fd, argv, env);
	close(fd[0]);
	close(fd[1]);
}
