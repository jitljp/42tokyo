/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:47:52 by mjeremy           #+#    #+#             */
/*   Updated: 2025/07/20 09:47:45 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/*
Prints an error message to standard error and exits the program.

- Outputs the provided message to STDERR_FILENO.
- Terminates the program with the specified exit code.
*/
void	exit_message(int code, char *msg)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	exit(code);
}

/*
Handles perror-style exit.

- Exits the program with the specified code.
- Error message will be printed by parent process.
- Uses exit code 2 for "No such file or directory" and 1 for "Permission denied".
*/
void	perror_exit(int code, char *cause, pid_t wait_pid)
{
	(void)wait_pid;
	(void)code;
	if (access(cause, F_OK) != 0)
		exit(2);
	else
		exit(1);
}

/*
Handles exit for command path errors.

- Exits with code 127 (command not found).
- Error message will be printed by parent process.
*/
void	path_exit(int code, char *cmd, char **env, pid_t wait_pid)
{
	(void)wait_pid;
	(void)env;
	free(cmd);
	exit(code);
}

/*
Handles exit after a failed execve call.

- Frees the command split array.
- Exits with code 127 (command not found).
- Error message will be printed by parent process.
*/
void	exec_exit(char **cmd_split, char *path, pid_t wait_pid)
{
	(void)wait_pid;
	(void)path;
	free_split(cmd_split);
	exit(127);
}
