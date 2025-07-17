/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:25:09 by mjeremy           #+#    #+#             */
/*   Updated: 2025/04/29 15:23:10 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Locates the last occurrence of the character c in the string s.
*/
char	*ft_strrchr(const char *s, int c)
{
	const char	*last;

	last = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			last = s;
		s++;
	}
	if (*s == (char)c)
		last = s;
	return ((char *)last);
}

/*
#include <stdio.h>

int	main(void)
{
	char	str[] = "Hello, World!";
	char	*result;

	result = ft_strrchr(str, 'o');
	if (result != NULL)
		printf("Last 'o' found at: %s\n", result);
	else
		printf("'o' not found.\n");

	result = ft_strrchr(str, 'l');
	if (result != NULL)
		printf("Last 'l' found at: %s\n", result);
	else
		printf("'l' not found.\n");

	result = ft_strrchr(str, 'z');
	if (result != NULL)
		printf("Last 'z' found at: %s\n", result);
	else
		printf("'z' not found.\n");

	result = ft_strrchr(str, '\0');
	if (result != NULL)
		printf("Found null terminator at address: %p\n", (void *)result);
	else
		printf("Null terminator not found.\n");

	return (0);
}
*/
