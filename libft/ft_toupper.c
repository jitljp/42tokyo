/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:48:13 by mjeremy           #+#    #+#             */
/*   Updated: 2025/04/29 15:23:33 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Converts a lowercase letter to its uppercase equivalent.
*/
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

/*
#include <stdio.h>

int	main(void)
{
	char	c;

	c = 'b';
	printf("%c -> %c\n", c, ft_toupper(c));
	c = 'G';
	printf("%c -> %c\n", c, ft_toupper(c));
	c = '3';
	printf("%c -> %c\n", c, ft_toupper(c));
	return (0);
}
*/
