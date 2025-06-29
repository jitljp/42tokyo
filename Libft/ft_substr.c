/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:49:19 by mjeremy           #+#    #+#             */
/*   Updated: 2025/04/29 17:17:50 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Allocates memory and returns a substring from string s,
starting at index start and of maximum length len.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = 0;
	while (s[s_len] != '\0')
		s_len++;
	if (start >= s_len)
		len = 0;
	if (len > s_len - start)
		len = s_len - start;
	sub_str = (char *)malloc((len + 1) * sizeof(char));
	if (!sub_str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub_str[i] = s[start + i];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*result;

	result = ft_substr("Hello World", 6, 5);
	if (result)
	{
		printf("[%s]\n", result); // should print [World]
		free(result);
	}
	result = ft_substr("abcdef", 2, 3);
	if (result)
	{
		printf("[%s]\n", result); // should print [cde]
		free(result);
	}
	result = ft_substr("42Tokyo", 10, 2);
	if (result)
	{
		printf("[%s]\n", result); // should print []
		free(result);
	}
	return (0);
}
*/
