/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 08:42:51 by mjeremy           #+#    #+#             */
/*   Updated: 2025/05/22 13:09:33 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	ft_handle_format(const char format, va_list args)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (format == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		count += ft_handle_pointer((uintptr_t)va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		count += ft_handle_decimal(va_arg(args, int));
	else if (format == 'u')
		count += ft_handle_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		count += ft_handle_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	if (!format)
		return (-1);
	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			count += ft_handle_format(format[i + 1], args);
			i++;
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
