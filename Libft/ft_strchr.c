/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:13:47 by mjeremy           #+#    #+#             */
/*   Updated: 2025/05/04 14:56:56 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Locates the first occurrence of the character c in the string s.
*/
char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

/*
#include <stdio.h>

int	main(void)
{
	char	str[] = "Hello, World!";
	char	*result;

	result = ft_strchr(str, 'W');
	if (result != NULL)
		printf("Found: %s\n", result);
	else
		printf("'W' not found.\n");

	result = ft_strchr(str, 'z');
	if (result != NULL)
		printf("Found: %s\n", result);
	else
		printf("'z' not found.\n");

	result = ft_strchr(str, '\0');
	if (result != NULL)
		printf("Found null terminator at: %p\n", (void *)result);
	else
		printf("Null terminator not found.\n");

	return (0);
}
*/
