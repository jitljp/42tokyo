/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 11:09:25 by mjeremy           #+#    #+#             */
/*   Updated: 2025/05/04 08:56:34 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
 Returns the number of characters needed to represent the given number,
 including space for a minus sign if the number is negative.
 */
static int	num_len(long nbr)
{
	int	len;

	len = 1;
	if (nbr < 0)
	{
		nbr = -nbr;
		len++;
	}
	while (nbr >= 10)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

/*
Converts the integer n to a null-terminated string.
Handles negative values and allocates memory with malloc.
Returns the resulting string or NULL if allocation fails.
*/
char	*ft_itoa(int n)
{
	char	*str;
	long	nbr;
	int		len;

	nbr = n;
	len = num_len(nbr);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nbr < 0)
		nbr = -nbr;
	while (len > 0)
	{
		len--;
		str[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

/*
#include <stdio.h>

int	main(void)
{
	int		test_vals[] = {0, 123, -123, 2147483647, -2147483648};
	int		i = 0;
	char	*result;

	while (i < 5)
	{
		result = ft_itoa(test_vals[i]);
		if (result)
			printf("ft_itoa(%d) = %s\n", test_vals[i], result);
		else
			printf("ft_itoa(%d) = NULL\n", test_vals[i]);
		free(result);
		i++;
	}
	return (0);
}
*/
