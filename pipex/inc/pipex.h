/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 12:18:50 by mjeremy           #+#    #+#             */
/*   Updated: 2025/07/16 12:02:12 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// unistd.h: Provides fork, pipe, dup2, execve, close, write, access for process1, process2, main, perror_exit, get_cmd_path
# include <unistd.h>
// stdio.h: Provides perror
# include <stdio.h>
// fcntl.h: Provides open and file control flags (O_RDONLY, O_CREAT, O_WRONLY) for process1, process2
# include <fcntl.h>
// stdlib.h: Provides malloc, free, exit for get_cmd_path, free_split, exit_message, perror_exit, path_exit, exec_exit
# include <stdlib.h>
// sys/wait.h: Provides waitpid for main, perror_exit, path_exit
# include <sys/wait.h>
# include "libft.h"

// Utility functions
void	wrap_up(pid_t pid1, int *fd);
char	*get_cmd_path(char *cmd, char **env);
void	free_split(char **arr);

// Error/exit utility functions
void	exit_message(int code, char *msg);
void	perror_exit(int code, char *cause, pid_t wait_pid);
void	path_exit(int code, char *cmd, char **env, pid_t wait_pid);
void	exec_exit(char **cmd_split, char *path, pid_t wait_pid);

#endif
