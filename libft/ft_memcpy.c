/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 13:12:31 by mjeremy           #+#    #+#             */
/*   Updated: 2025/05/04 15:02:43 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Copies n bytes from the memory area src to the memory area dest.
*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*pt_dest;
	const unsigned char	*pt_src;

	if (n == 0 || dest == src)
		return (dest);
	pt_dest = (unsigned char *)dest;
	pt_src = (const unsigned char *)src;
	while (n > 0)
	{
		*pt_dest = *pt_src;
		pt_dest++;
		pt_src++;
		n--;
	}
	return (dest);
}

/*
#include <stdio.h>

int	main(void)
{
	char	src[20] = "Hello World!";
	char	dest[20];

	ft_memcpy(dest, src, 12);
	printf("%s\n", dest);
	return (0);
}
*/
