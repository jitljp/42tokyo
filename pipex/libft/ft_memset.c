/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 12:27:18 by mjeremy           #+#    #+#             */
/*   Updated: 2025/05/04 14:22:13 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Fills the first n bytes of the memory area s with the byte value c.
*/
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*pt;

	pt = (unsigned char *)s;
	while (n > 0)
	{
		*pt = (unsigned char)c;
		pt++;
		n--;
	}
	return (s);
}

/*
#include <stdio.h>

int	main(void)
{
	char	str[20] = "Hello World!";

	printf("%s\n", str);
	ft_memset(str + 6, 129, 5);
	printf("%s\n", str);
	return (0);
}
*/
