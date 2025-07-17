/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 08:42:35 by mjeremy           #+#    #+#             */
/*   Updated: 2025/05/29 14:45:12 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_handle_hex(unsigned int n, char format)
{
	char	buffer[8];
	char	*hex;
	int		i;
	int		len;

	if (format == 'X')
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (n == 0)
		return (ft_putchar('0'));
	i = 0;
	while (n)
	{
		buffer[i] = hex[n % 16];
		n /= 16;
		i++;
	}
	len = i;
	while (i--)
		ft_putchar(buffer[i]);
	return (len);
}

int	ft_handle_pointer(uintptr_t ptr)
{
	char	buffer[16];
	char	*hex;
	int		i;
	int		len;

	if (ptr == 0)
		return (ft_putstr("(nil)"));
	hex = "0123456789abcdef";
	i = 0;
	while (ptr)
	{
		buffer[i] = hex[ptr % 16];
		ptr /= 16;
		i++;
	}
	len = ft_putstr("0x");
	while (i--)
		len += ft_putchar(buffer[i]);
	return (len);
}

int	ft_handle_decimal(int n)
{
	char	*str;
	int		len;

	str = ft_itoa(n);
	if (!str)
		return (-1);
	len = ft_putstr(str);
	free(str);
	return (len);
}

int	ft_handle_unsigned(unsigned int n)
{
	char	*str;
	int		len;

	str = ft_itoa_unsigned(n);
	if (!str)
		return (-1);
	len = ft_putstr(str);
	free(str);
	return (len);
}
