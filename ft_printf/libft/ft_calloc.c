/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:36:57 by mjeremy           #+#    #+#             */
/*   Updated: 2025/05/09 13:08:19 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Allocates memory for an array of nmemb elements of size bytes each,
and initializes all bytes to zero.
*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			i;
	size_t			len;

	if (size != 0 && (nmemb * size) / size != nmemb)
		return (NULL);
	len = nmemb * size;
	ptr = malloc(len);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

/*
#include <stdio.h>

int	main(void)
{
	int		*arr;
	size_t	i;

	arr = (int *)ft_calloc(5, sizeof(int));
	if (!arr)
	{
		printf("Allocation failed\n");
		return (1);
	}
	i = 0;
	while (i < 5)
	{
		printf("arr[%zu] = %d\n", i, arr[i]);
		i++;
	}
	return (0);
}
*/
