/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:45:22 by mjeremy           #+#    #+#             */
/*   Updated: 2025/05/10 10:25:59 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Frees each allocated word in the array and the array itself.
Used to clean up on allocation failure.
*/
static void	free_split(char **arr, int i)
{
	while (i > 0)
		free(arr[--i]);
	free(arr);
}

/*
Counts the number of words in the string separated by the delimiter 'c'.
A word is a sequence of non-delimiter characters.
*/
static int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

/*
Duplicates a substring of length 'len' from string 's'.
Returns the new null-terminated string or NULL on failure.
*/
static char	*word_dup(char *s, int len)
{
	char	*word;
	int		i;

	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

/*
Fills the array with duplicated words from the input string.
Returns 1 on success, or 0 on failure after freeing memory.
*/
static int	fill_split(char **arr, char const *s, char c)
{
	int		i;
	char	*start;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			start = (char *)s;
			while (*s && *s != c)
				s++;
			arr[i] = word_dup(start, s - start);
			if (!arr[i])
			{
				free_split(arr, i);
				return (0);
			}
			i++;
		}
	}
	arr[i] = NULL;
	return (1);
}

/*
Splits the input string into an array of words using the delimiter.
Returns a null-terminated array or NULL on allocation failure.
*/
char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	arr = malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	if (!fill_split(arr, s, c))
		return (NULL);
	return (arr);
}

/*
#include <stdio.h>

int	main(void)
{
	char	**result;
	int		i;

	result = ft_split(",,,hello,,world,this,is,libft,", ',');
	if (!result)
	{
		printf("Allocation failed\n");
		return (1);
	}
	i = 0;
	while (result[i])
	{
		printf("result[%d] = %s\n", i, result[i]);
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
}
*/
