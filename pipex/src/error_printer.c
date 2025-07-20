/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_printer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 10:00:00 by mjeremy           #+#    #+#             */
/*   Updated: 2025/07/20 10:00:00 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/*
Handles error printing for the first process.
*/
static void	handle_first_process_error(int status1, char **argv, char **env)
{
	if (WIFEXITED(status1) && WEXITSTATUS(status1) != 0)
	{
		if (WEXITSTATUS(status1) == 127)
			print_cmd_error(argv[2], env);
		else if (WEXITSTATUS(status1) == 2)
		{
			ft_putstr_fd("bash: ", STDERR_FILENO);
			ft_putstr_fd(argv[1], STDERR_FILENO);
			ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
		}
		else
		{
			ft_putstr_fd("bash: ", STDERR_FILENO);
			ft_putstr_fd(argv[1], STDERR_FILENO);
			ft_putstr_fd(": Permission denied\n", STDERR_FILENO);
		}
	}
}

/*
Handles error printing for the second process.
*/
static void	handle_second_process_error(int status2, char **argv, char **env)
{
	if (WIFEXITED(status2) && WEXITSTATUS(status2) != 0)
	{
		if (WEXITSTATUS(status2) == 127)
			print_cmd_error(argv[3], env);
		else if (WEXITSTATUS(status2) == 3)
		{
			ft_putstr_fd("bash: ", STDERR_FILENO);
			ft_putstr_fd(argv[4], STDERR_FILENO);
			ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
		}
		else
		{
			ft_putstr_fd("bash: ", STDERR_FILENO);
			ft_putstr_fd(argv[4], STDERR_FILENO);
			ft_putstr_fd(": Permission denied\n", STDERR_FILENO);
		}
	}
}

/*
Prints error messages in the correct order based on child process status.
*/
void	print_errors(int status1, int status2, char **argv, char **env)
{
	handle_first_process_error(status1, argv, env);
	handle_second_process_error(status2, argv, env);
}
