/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:29:59 by mjeremy           #+#    #+#             */
/*   Updated: 2025/06/11 15:28:10 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 * Returns the length of the string s.
 * Returns 0 if s is NULL.
 */
int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

/*
 * Searches for the first occurrence of character c in string s.
 * Returns a pointer to it, or NULL if not found.
 */
char	*ft_strchr(char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&s[i]);
	return (NULL);
}

/*
* Helper function that copies stash and buf into dst and null-terminates it.
*/
static void	copy_and_join(char *joined, char *stash, char *buf)
{
	int	i;
	int	j;

	i = 0;
	if (stash)
	{
		while (stash[i])
		{
			joined[i] = stash[i];
			i++;
		}
	}
	j = 0;
	if (buf)
	{
		while (buf[j])
			joined[i++] = buf[j++];
	}
	joined[i] = '\0';
}

/*
 * Allocates and returns a new string formed by joining stash and buf.
 * Frees stash and returns NULL if memory allocation fails.
 */
char	*ft_strjoin(char *stash, char *buf)
{
	char	*joined;

	if (!stash)
	{
		stash = malloc(1);
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	if (!buf)
		return (stash);
	joined = malloc(ft_strlen(stash) + ft_strlen(buf) + 1);
	if (!joined)
	{
		free(stash);
		return (NULL);
	}
	copy_and_join(joined, stash, buf);
	free(stash);
	return (joined);
}
