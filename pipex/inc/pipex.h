/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 12:18:50 by mjeremy           #+#    #+#             */
/*   Updated: 2025/07/19 13:42:50 by mjeremy          ###   ########.fr       */
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
char	*get_cmd_path(char *cmd, char **env);
void	free_split(char **arr);
int		is_empty_cmd(char *cmd, int fd_to_close, pid_t pid);
void	setup_fds(int fd_in, int fd_out, int *pipe_fd);
// Error handling functions
void	print_cmd_error(char *cmd, char **env);
void	print_errors(int status1, int status2, char **argv, char **env);
// Child process functions
void	create_first_child(int *fd, char **argv, char **env, pid_t *pid1);
void	create_second_child(int *fd, char **argv, char **env, pid_t *pid2);
void	process1(int *fd, char **argv, char **env);
void	process2(int *fd, char **argv, char **env);

#endif
