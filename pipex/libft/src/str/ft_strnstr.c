/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:04:52 by mjeremy           #+#    #+#             */
/*   Updated: 2025/04/29 15:22:58 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Locates the first occurrence of the string little within big,
searching at most len characters.
*/
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (big[i + j] && big[i + j] == little[j] && (i + j) < len)
			j++;
		if (little[j] == '\0')
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len);

int	main(void)
{
	char	big[] = "Hello, World!";
	char	*little;

	little = "World";
	printf("Test 1 (find 'World'): %s\n", ft_strnstr(big, little, 13));

	little = "World";
	printf("Test 2 (search too short): %s\n", ft_strnstr(big, little, 5));

	little = "";
	printf("Test 3 (empty search string): %s\n", ft_strnstr(big, little, 5));

	little = "42";
	printf("Test 4 (little not found): %s\n", ft_strnstr(big, little, 13));

	return (0);
}
*/
