/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:06:07 by mjeremy           #+#    #+#             */
/*   Updated: 2025/05/09 14:40:41 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Allocates memory and creates a duplicate of the given string s.
*/
char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	dup = (char *)malloc(i + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*copy1;
	char	*copy2;

	copy1 = ft_strdup("hello");
	copy2 = ft_strdup("libft");
	if (copy1 && copy2)
	{
		printf("%s\n", copy1);
		printf("%s\n", copy2);
	}
	return (0);
}
*/
