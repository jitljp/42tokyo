/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:47:01 by mjeremy           #+#    #+#             */
/*   Updated: 2025/05/09 11:29:23 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Appends src to dst, ensuring the total length does not exceed size,
and null-terminates if there is at least one free byte in dst.
*/
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;
	size_t	i;
	size_t	j;

	d_len = 0;
	s_len = 0;
	while (dst[d_len] && d_len < size)
		d_len++;
	while (src[s_len])
		s_len++;
	if (size == d_len)
		return (size + s_len);
	i = d_len;
	j = 0;
	while (src[j] && i < size - 1)
		dst[i++] = src[j++];
	if (i < size)
		dst[i] = '\0';
	return (d_len + s_len);
}

/*
#include <stdio.h>
int	main(void)
{
	char			dest[20] = "Hello, ";
	char			src[] = "world!";
	unsigned int	size = 20;
	unsigned int	result;

	result = ft_strlcat(dest, src, size);
	printf("Resulting string: %s\n", dest);
	printf("Total length: %u\n", result);
	return (0);
}
*/
