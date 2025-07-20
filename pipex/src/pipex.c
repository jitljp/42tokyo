/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 12:46:18 by mjeremy           #+#    #+#             */
/*   Updated: 2025/07/20 12:55:47 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/*
Executes the given command in the current process.

- Determines the full path of the command, either absolute
   or by searching in PATH.
- If the command is not found, exits with status 127 and an error message.
- Uses execve to replace the current process image with the command.
- If execve fails, handles cleanup and exits with an error.
*/
static void	execute_cmd(char **cmd, char **env)
{
	char	*path;
	char	*cmd_dup;

	if (ft_strchr(cmd[0], '/'))
		path = cmd[0];
	else
		path = get_cmd_path(cmd[0], env);
	if (!path)
	{
		cmd_dup = ft_strdup(cmd[0]);
		free_split(cmd);
		free(cmd_dup);
		exit(127);
	}
	execve(path, cmd, env);
	free_split(cmd);
	exit(127);
}

/*
Handles the first process (child) in the pipeline.

- Opens the input file for reading.
- Exits with an error if the file cannot be opened.
- Checks for empty commands and handles accordingly.
- Splits the command string into arguments.
- Sets up file descriptors: redirects stdin to infile
   and stdout to the pipe write end.
- Executes the command.
*/
void	process1(int *fd, char **argv, char **env)
{
	int		infile;
	char	**cmd;

	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
	{
		if (access(argv[1], F_OK) != 0)
			exit(2);
		else
			exit(1);
	}
	is_empty_cmd(argv[2], infile, 0);
	cmd = ft_split(argv[2], ' ');
	if (!cmd)
		exit(1);
	setup_fds(infile, fd[1], fd);
	execute_cmd(cmd, env);
}

/*
Handles output file error checking for non-existent directories.
*/
static void	check_output_file_error(char *file_path)
{
	char	*last_slash;
	char	*parent_dir;
	char	temp;
	int		dir_exists;

	last_slash = ft_strrchr(file_path, '/');
	if (last_slash && last_slash != file_path)
	{
		temp = *last_slash;
		*last_slash = '\0';
		parent_dir = ft_strdup(file_path);
		*last_slash = temp;
		dir_exists = (access(parent_dir, F_OK) == 0);
		free(parent_dir);
		if (!dir_exists)
			exit(3);
	}
	exit(1);
}

/*
Handles the second process (child) in the pipeline.

- Opens the output file for writing, creating or truncating it.
- Exits with an error if the file cannot be opened.
- Checks for empty commands and handles accordingly.
- Splits the command string into arguments.
- Sets up file descriptors: redirects stdin to the pipe read end
   and stdout to outfile.
- Executes the command.
*/
void	process2(int *fd, char **argv, char **env)
{
	int		outfile;
	char	**cmd;

	outfile = open(argv[4], O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (outfile < 0)
		check_output_file_error(argv[4]);
	is_empty_cmd(argv[3], outfile, 0);
	cmd = ft_split(argv[3], ' ');
	if (!cmd)
		exit(1);
	setup_fds(fd[0], outfile, fd);
	execute_cmd(cmd, env);
}

/*
Entry point of the Pipex program.

- Validates the number of arguments (must be exactly 5).
- Creates a pipe for inter-process communication.
- Forks twice to create two child processes.
- First child runs process1 to handle the first command.
- Second child runs process2 to handle the second command.
- Parent waits for both children and prints errors in correct order.
- Returns the exit code of the second command.

Errors in pipe or fork result in immediate exit with a message.
*/
int	main(int argc, char **argv, char **env)
{
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];
	int		status1;
	int		status2;

	if (argc != 5)
	{
		ft_putstr_fd("Usage: ./pipex infile cmd1 cmd2 outfile\n",
			STDERR_FILENO);
		exit(1);
	}
	create_first_child(fd, argv, env, &pid1);
	create_second_child(fd, argv, env, &pid2);
	waitpid(pid1, &status1, 0);
	waitpid(pid2, &status2, 0);
	print_errors(status1, status2, argv, env);
	if (WEXITSTATUS(status2) == 3)
		return (1);
	return (WEXITSTATUS(status2));
}
