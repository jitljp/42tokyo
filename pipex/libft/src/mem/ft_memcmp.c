/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:52:36 by mjeremy           #+#    #+#             */
/*   Updated: 2025/04/29 15:19:30 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Compares the first n bytes of the memory areas s1 and s2.
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				i;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	i = 0;
	while (i < n && *str1 == *str2)
	{
		str1++;
		str2++;
		i++;
	}
	if (i == n)
		return (0);
	return (*str1 - *str2);
}

/*
#include <stdio.h>

int	main(void)
{
	char	str1[] = "abcdef";
	char	str2[] = "abcdeg";
	char	str3[] = "abc\0def";
	char	str4[] = "abc\0xyz";

	printf("Test 1 (equal): %d\n", ft_memcmp(str1, str1, 6));
	printf("Test 2 ('f' vs 'g'): %d\n", ft_memcmp(str1, str2, 6));
	printf("Test 3 (null in middle): %d\n", ft_memcmp(str3, str4, 4));
	printf("Test 4 (null in middle): %d\n", ft_memcmp(str3, str4, 7));

	return (0);
}
*/
