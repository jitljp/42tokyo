/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:57:52 by mjeremy           #+#    #+#             */
/*   Updated: 2025/05/01 13:08:39 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Applies the function f to each character of the string s,
passing its index and the address of each character.
Allows in-place modification of the string.
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

/*
#include <stdio.h>

void	mask_even_index(unsigned int i, char *c)
{
	if (i % 2 == 0)
		*c = '*';
}

int	main(void)
{
	char	str[] = "helloworld";

	ft_striteri(str, mask_even_index);
	printf("Modified string: %s\n", str);
	return (0);
}
*/
