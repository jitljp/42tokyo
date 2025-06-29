/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:00:08 by mjeremy           #+#    #+#             */
/*   Updated: 2025/05/01 17:07:35 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Allocates memory and returns a new string,
which is the result of the concatenation of s1 and s2.
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (*s1)
	{
		str[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		str[i] = *s2;
		i++;
		s2++;
	}
	str[i] = '\0';
	return (str);
}

/*
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	main(void)
{
	char	*result;

	result = ft_strjoin("Hello", "World");
	if (result)
	{
		printf("%s\n", result);
		free(result);
	}
	result = ft_strjoin(" ", "42");
	if (result)
	{
		printf("%s\n", result);
		free(result);
	}
	return (0);
}
*/
