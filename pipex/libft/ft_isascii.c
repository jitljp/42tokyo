/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 12:11:38 by mjeremy           #+#    #+#             */
/*   Updated: 2025/04/29 15:17:46 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Checks if the character is part of the standard ASCII character set.
*/
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_isascii(65));    // Should print 1 ('A')
	printf("%d\n", ft_isascii(200));   // Should print 0 (out of ASCII range)
	return (0);
}
*/
