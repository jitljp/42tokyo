/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:52:47 by mjeremy           #+#    #+#             */
/*   Updated: 2025/04/29 15:23:22 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Converts an uppercase letter to its lowercase equivalent.
*/
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

/*
#include <stdio.h>

int	main(void)
{
	char	c;

	c = 'b';
	printf("%c -> %c\n", c, ft_tolower(c));
	c = 'G';
	printf("%c -> %c\n", c, ft_tolower(c));
	c = '3';
	printf("%c -> %c\n", c, ft_tolower(c));
	return (0);
}
*/
