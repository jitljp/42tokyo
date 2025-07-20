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
		exit_message(1, "pipe error\n");
	*pid1 = fork();
	if (*pid1 == -1)
		exit_message(1, "fork error\n");
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
		exit_message(1, "fork error\n");
	if (*pid2 == 0)
		process2(fd, argv, env);
	close(fd[0]);
	close(fd[1]);
}
