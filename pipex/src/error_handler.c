/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 14:00:00 by mjeremy           #+#    #+#             */
/*   Updated: 2025/07/20 09:50:25 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/*
Determines if PATH exists and if command has a slash.
*/
static void	get_error_info(char **env, char *cmd, int *path_exists,
	int *has_slash)
{
	int	i;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	*path_exists = (env[i] != NULL);
	*has_slash = (ft_strchr(cmd, '/') != NULL);
}

/*
Prints "No such file or directory" error message.
*/
static void	print_no_such_file(char *cmd)
{
	char	*space_pos;
	char	*cmd_name;

	cmd_name = cmd;
	space_pos = ft_strchr(cmd_name, ' ');
	if (space_pos)
		*space_pos = '\0';
	ft_putstr_fd("bash: ", STDERR_FILENO);
	ft_putstr_fd(cmd_name, STDERR_FILENO);
	ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
}

/*
Prints error message for command not found or file not found.
*/
void	print_cmd_error(char *cmd, char **env)
{
	int	path_exists;
	int	has_slash;

	get_error_info(env, cmd, &path_exists, &has_slash);
	if (!path_exists || has_slash)
		print_no_such_file(cmd);
	else
	{
		ft_putstr_fd(cmd, STDERR_FILENO);
		ft_putstr_fd(": command not found\n", STDERR_FILENO);
	}
}
