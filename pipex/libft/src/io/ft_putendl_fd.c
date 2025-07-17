/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:22:14 by mjeremy           #+#    #+#             */
/*   Updated: 2025/05/01 13:30:03 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Writes the string s followed by a newline to the given file descriptor fd.
If s is NULL, nothing is written.
*/
void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

/*
int	main(void)
{
	ft_putendl_fd("Hello, stdout!", 1); // fd 1 = stdout
	ft_putendl_fd("Hello, stderr!", 2); // fd 2 = stderr
	return (0);
}
*/
