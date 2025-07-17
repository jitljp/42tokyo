/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:58:55 by mjeremy           #+#    #+#             */
/*   Updated: 2025/04/29 15:43:21 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Searches for the first occurrence of the byte c
in the first n bytes of the memory area s.
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	unsigned_c;
	size_t			i;

	ptr = (unsigned char *)s;
	unsigned_c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == unsigned_c)
			return (&ptr[i]);
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>

int	main(void)
{
	char	str[] = "Hello, World!";
	char	*result;

	result = ft_memchr(str, 'W', 13);
	if (result != NULL)
		printf("Found 'W' at: %s\n", result);
	else
		printf("'W' not found.\n");

	result = ft_memchr(str, 'z', 13);
	if (result != NULL)
		printf("Found 'z' at: %s\n", result);
	else
		printf("'z' not found.\n");

	result = ft_memchr(str, '\0', 14);
	if (result != NULL)
		printf("Found null terminator at address: %p\n", (void *)result);
	else
		printf("Null terminator not found.\n");

	return (0);
}
*/
