/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 12:18:50 by mjeremy           #+#    #+#             */
/*   Updated: 2025/07/16 17:22:53 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// fork, pipe, dup2, execve, close, write, access,
# include <unistd.h>
// perror
# include <stdio.h>
// open and file control flags (O_RDONLY, O_CREAT, O_WRONLY) 
# include <fcntl.h>
// free, exit, free_split, exit_message, perror_exit, path_exit, exec_exit
# include <stdlib.h>
// waitpid for main, perror_exit, path_exit
# include <sys/wait.h>
# include "libft.h"

// Utility functions
void	wrap_up(pid_t pid1, int *fd);
char	*get_cmd_path(char *cmd, char **env);
void	free_split(char **arr);
int		is_empty_cmd(char *cmd, char **env, int fd_to_close, pid_t pid);
void	setup_fds(int fd_in, int fd_out, int *pipe_fd);
// Error/exit utility functions
void	exit_message(int code, char *msg);
void	perror_exit(int code, char *cause, pid_t wait_pid);
void	path_exit(int code, char *cmd, char **env, pid_t wait_pid);
void	exec_exit(char **cmd_split, char *path, pid_t wait_pid);

#endif
