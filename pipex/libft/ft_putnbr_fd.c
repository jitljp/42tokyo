/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:31:08 by mjeremy           #+#    #+#             */
/*   Updated: 2025/05/01 13:35:39 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Writes the integer n to the given file descriptor fd.
*/
void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}

/*
int	main(void)
{
	ft_putnbr_fd(42, 1);
	write(1, "\n", 1);

	ft_putnbr_fd(2147483647, 1);
	write(1, "\n", 1);

	ft_putnbr_fd(0, 1);
	write(1, "\n", 1);

	ft_putnbr_fd(-2147483648, 1); // INT_MIN
	write(1, "\n", 1);

	return (0);
}
*/
