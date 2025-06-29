/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeremy <mjeremy@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 08:42:58 by mjeremy           #+#    #+#             */
/*   Updated: 2025/05/22 09:28:01 by mjeremy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include "../libft/libft.h"

int			ft_printf(const char *format, ...);
int			ft_handle_pointer(uintptr_t ptr);
int			ft_handle_decimal(int n);
int			ft_handle_unsigned(unsigned int n);
int			ft_handle_hex(unsigned int n, char format);
int			ft_putchar(char c);
int			ft_putstr(char *str);
char		*ft_itoa_unsigned(unsigned int n);

#endif
