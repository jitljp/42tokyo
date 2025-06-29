/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 13:36:33 by mjeremy           #+#    #+#             */
/*   Updated: 2025/05/04 15:21:54 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Copies n bytes from src to dest, handling overlapping memory areas safely.
*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*pt_dest;
	const unsigned char	*pt_src;

	if (n == 0 || dest == src)
		return (dest);
	pt_dest = (unsigned char *)dest;
	pt_src = (const unsigned char *)src;
	if (pt_dest < pt_src)
	{
		while (n-- > 0)
		{
			*pt_dest++ = *pt_src++;
		}
	}
	else
	{
		pt_dest += n;
		pt_src += n;
		while (n-- > 0)
		{
			*--pt_dest = *--pt_src;
		}
	}
	return (dest);
}

/*
#include <stdio.h>

int	main(void)
{
	char	str[20] = "Hello World!";

	ft_memmove(str + 6, str, 5);
	printf("%s\n", str);
	return (0);
}
*/
