/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 11:31:59 by mjeremy           #+#    #+#             */
/*   Updated: 2025/05/09 16:02:44 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Applies the function f to each character of the string s,
passing its index and the character as arguments.
Returns a new string created from successive applications of f.
Returns NULL if allocation fails or s is NULL.
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_s;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
		i++;
	new_s = (char *)malloc(sizeof(char) * (i + 1));
	if (!new_s)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		new_s[i] = f(i, s[i]);
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}

/*
#include <stdio.h>

char	modify(unsigned int i, char c)
{
	return (c + i);
}

int	main(void)
{
	char	*input = "abcde";
	char	*result;

	result = ft_strmapi(input, modify);
	if (result)
	{
		printf("Original: %s\n", input);
		printf("Modified: %s\n", result);
		free(result);
	}
	return (0);
}
*/
