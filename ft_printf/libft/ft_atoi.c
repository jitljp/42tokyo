/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:27:30 by mjeremy           #+#    #+#             */
/*   Updated: 2025/05/04 13:38:12 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Converts the initial part of the string to an integer,
ignoring leading whitespace.
*/
int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	int		result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return ((int)result * sign);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_atoi("42"));
	printf("%d\n", ft_atoi("   -42"));
	printf("%d\n", ft_atoi("  +123abc"));
	printf("%d\n", ft_atoi("--42"));
	printf("%d\n", ft_atoi("+-42"));
	printf("%d\n", ft_atoi("abc"));
	printf("%d\n", ft_atoi("  2147483647"));
	printf("%d\n", ft_atoi("  -2147483648"));
	printf("%d\n", ft_atoi("  3147483647"));
	printf("%d\n", ft_atoi("  -3147483648"));
	return (0);
}
*/
