/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:37:33 by mjeremy           #+#    #+#             */
/*   Updated: 2025/06/11 10:55:51 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	len = ft_strlen(stash + start);
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
	while (!ft_strchr(stash, '\n') && bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buf);
			free(stash);
			return (NULL);
		}
		buf[bytes] = '\0';
		stash = ft_strjoin(stash, buf);
		if (!stash)
			break ;
	}
	free(buf);
	return (stash);
}

/*
 * Primary function that returns the next line from the given file descriptor.
 * Uses a static variable to store leftover data between calls.
 * BONUS: Changed stash to array.
 * stash[1024] = no OPEN_MAX on 42 system
 */
char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = read_fd(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	if (!*stash[fd])
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	line = extract_line(stash[fd]);
	if (!line)
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	stash[fd] = trim_stash(stash[fd]);
	return (line);
}

// #include <fcntl.h>    // open
// #include <stdio.h>    // printf, perror
// #include <unistd.h>   // close

// int	main(void)
// {
// 	int		fd1, fd2;
// 	char	*line1, *line2;

// 	fd1 = open("./tests/test1.txt", O_RDONLY);
// 	fd2 = open("./tests/test4.txt", O_RDONLY);

// 	if (fd1 == -1 || fd2 == -1)
// 	{
// 		perror("open");
// 		return (1);
// 	}

// 	printf("Files opened: fd1 = %d, fd2 = %d\n", fd1, fd2);
// 	fflush(stdout);

// 	// Read 3 lines interleaved
// 	for (int i = 0; i < 3; i++)
// 	{
// 		line1 = get_next_line(fd1);
// 		line2 = get_next_line(fd2);

// 		if (line1)
// 		{
// 			printf("fd1 LINE: %s", line1);
// 			free(line1);
// 		}
// 		else
// 			printf("fd1 LINE: (NULL)\n");

// 		if (line2)
// 		{
// 			printf("fd2 LINE: %s", line2);
// 			free(line2);
// 		}
// 		else
// 			printf("fd2 LINE: (NULL)\n");

// 		fflush(stdout);
// 	}

// 	close(fd1);
// 	close(fd2);
// 	printf("Both files closed.\n");
// 	return (0);
// }
