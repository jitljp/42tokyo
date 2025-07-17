/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:37:33 by mjeremy           #+#    #+#             */
/*   Updated: 2025/06/14 08:14:46 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/*
 * Helper function to copy remaining content after newline
 */
static char	*copy_remaining(char *stash, int start)
{
	char	*new;
	int		j;
	int		len;

	if (!stash || !stash[start])
	{
		free(stash);
		return (NULL);
	}
	len = ft_strlen((const char *)(stash + start));
	new = malloc(len + 1);
	if (!new)
	{
		free(stash);
		return (NULL);
	}
	j = 0;
	while (stash[start])
		new[j++] = stash[start++];
	new[j] = '\0';
	free(stash);
	return (new);
}

/*
 * Removes the extracted line from the stash,
 * keeping only the remaining characters after the newline.
 */
static char	*trim_stash(char *stash)
{
	int		i;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	return (copy_remaining(stash, i));
}

/*
 * Extracts a line (up to and including the first newline, if any)
 * from the stash and returns it as a new allocated string.
 */
static char	*extract_line(char *stash)
{
	int		len;
	char	*line;

	len = 0;
	while (stash[len] && stash[len] != '\n')
		len++;
	if (stash[len] == '\n')
		len++;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	len = 0;
	while (stash[len] && stash[len] != '\n')
	{
		line[len] = stash[len];
		len++;
	}
	if (stash[len] == '\n')
	{
		line[len] = '\n';
		len++;
	}
	line[len] = '\0';
	return (line);
}

/*
 * Reads from the file descriptor into a buffer until a newline
 * is found or EOF is reached. Appends read data to the stash.
 */
static char	*read_fd(int fd, char *stash)
{
	char	*buf;
	int		bytes;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free(stash), NULL);
	bytes = 1;
	while (!ft_strchr((const char *)stash, '\n') && bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buf);
			free(stash);
			return (NULL);
		}
		buf[bytes] = '\0';
		stash = ft_strjoin((const char *)stash, (const char *)buf);
		if (!stash)
			break ;
	}
	free(buf);
	return (stash);
}

/*
 * Primary function that returns the next line from the given file descriptor.
 * Uses a static variable (stash) to store leftover data between calls.
 */
char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= (long long)INT_MAX)
		return (NULL);
	stash = read_fd(fd, stash);
	if (!stash)
		return (NULL);
	if (!*stash)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = extract_line(stash);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = trim_stash(stash);
	return (line);
}

// #include <fcntl.h>    // open
// #include <stdio.h>    // printf, perror
// #include <unistd.h>   // close

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("./tests/test4.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("open");  // show why open failed
// 		return (1);
// 	}

// 	printf("File opened. fd = %d\n", fd);
// 	fflush(stdout);  // force printf to show output immediately

// 	while ((line = get_next_line(fd)))
// 	{
// 		printf("LINE: %s", line);  // LINE: <line content>
// 		fflush(stdout);            // force output immediately
// 		free(line);
// 	}

// 	printf("End of file or error.\n");
// 	fflush(stdout);

// 	close(fd);
// 	return (0);
// }
