/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:35:17 by mjeremy           #+#    #+#             */
/*   Updated: 2025/04/29 15:22:41 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Compares up to n characters of the strings s1 and s2.
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && *s1 == *s2 && *s1 != '\0')
	{
		s1++;
		s2++;
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

/*
#include <stdio.h>
int main(void)
{
	printf("Test 1 (equal, n=5): %d\n", ft_strncmp("hello", "hello", 5));
	printf("Test 2 (s1 < s2, n=5): %d\n", ft_strncmp("apple", "banana", 5));
	printf("Test 3 (s1 > s2, n=4): %d\n", ft_strncmp("grape", "grap", 4));
	printf("Test 4 (equal up to n=3): %d\n", ft_strncmp("abcdef", "abcxyz", 3));
	printf("Test 5 (s1 empty, n=1): %d\n", ft_strncmp("", "nonempty", 1));
	printf("Test 6 (s2 empty, n=1): %d\n", ft_strncmp("nonempty", "", 1));
	printf("Test 7 (s1 non-ASCII): %d\n", ft_strncmp("\200", "\0", 2));

	return 0;
}
*/
