/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 12:55:35 by mjeremy           #+#    #+#             */
/*   Updated: 2025/05/04 14:36:14 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Sets the first n bytes of the memory area pointed to by s to zero.
*/
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*pt;

	pt = (unsigned char *)s;
	while (n > 0)
	{
		*pt = 0;
		pt++;
		n--;
	}
}

/*
#include <stdio.h>

int	main(void)
{
	char	str[20] = "Hello World!";

	printf("%s\n", str);
	ft_bzero(str + 5, 6);
	printf("%s\n", str);
	return (0);
}
*/
