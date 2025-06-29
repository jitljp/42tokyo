/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:41:43 by mjeremy           #+#    #+#             */
/*   Updated: 2025/05/09 10:14:30 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Copies src to dst, ensuring at most size - 1 characters are copied
and dst is null-terminated.
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	c;

	i = 0;
	while (src[i] != '\0')
		i++;
	if (size > 0)
	{
		c = 0;
		while (c < size - 1 && src[c] != '\0')
		{
			dst[c] = src[c];
			c++;
		}
		dst[c] = '\0';
	}
	return (i);
}

/*
#include <stdio.h>
int	main()
{
	char src[] = "Hello, World!";
	char dest[20];
	unsigned int size = 10;
	unsigned int length = ft_strlcpy(dest, src, size);
	printf("Source: %s\n", src);
	printf("Destination: %s\n", dest);
	printf("Length of source: %u\n", length);
	return 0;
}
*/
