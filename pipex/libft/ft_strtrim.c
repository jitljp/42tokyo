/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:36:28 by mjeremy           #+#    #+#             */
/*   Updated: 2025/05/01 10:52:50 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 Checks if a character exists in the set of characters to trim.
 Returns 1 if the character should be trimmed, 0 otherwise.
 */
static int	should_trim(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/*
 Allocates and returns a new string, trimmed from both ends
 of any characters found in 'set'. Returns NULL if allocation fails.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*trimmed_str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] != '\0' && should_trim(set, s1[start]))
		start++;
	end = start;
	while (s1[end] != '\0')
		end++;
	while (end > start && should_trim(set, s1[end - 1]))
		end--;
	len = end - start;
	trimmed_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!trimmed_str)
		return (NULL);
	len = 0;
	while (start < end)
		trimmed_str[len++] = s1[start++];
	trimmed_str[len] = '\0';
	return (trimmed_str);
}

/*
#include <stdio.h>

int	main(void)
{
	char const	*big = "+++Hello World!!!+++";
	char const	*little = "+!";
	char		*result;

	result = ft_strtrim(big, little);
	if (result)
	{
		printf("Original: \"%s\"\n", big);
		printf("Trimmed:  \"%s\"\n", result);
		free(result);
	}
	else
		printf("Memory allocation failed.\n");
	return (0);
}
*/
