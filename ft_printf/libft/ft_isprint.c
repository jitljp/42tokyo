/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 12:13:17 by mjeremy           #+#    #+#             */
/*   Updated: 2025/04/29 15:18:56 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Checks if the character is printable, including space.
*/
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_isprint('A'));  // Should print 1
	printf("%d\n", ft_isprint('\n')); // Should print 0
	return (0);
}
*/
