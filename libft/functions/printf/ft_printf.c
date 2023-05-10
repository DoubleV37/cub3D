/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 08:30:17 by jduval            #+#    #+#             */
/*   Updated: 2023/05/10 13:38:28 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdarg.h>

static void	ft_putnbr_printf(long unsigned int n, int fd)
{
	if (n >= 10)
		ft_putnbr_printf(n / 10, fd);
	n = n % 10 + '0';
	write(fd, &n, 1);
}

int	ft_prep(long int nbr, int fd, int len, int base)
{
	if (nbr < 0)
	{
		write(1, "-", fd);
		len++;
		nbr *= (-1);
	}
	len += ft_nbrlen(nbr, base);
	ft_putnbr_printf((long unsigned int)nbr, fd);
	return (len);
}

static int	ft_put_hexa(char format, va_list arg_point, int fd)
{
	int	len;

	len = 0;
	if (format == 'p')
		len = ft_print_p(va_arg(arg_point, long unsigned), fd, len);
	else if (format == 'x' || format == 'X')
		len = ft_putnbr_hex(va_arg(arg_point, unsigned int), format, fd, len);
	return (len);
}

static int	ft_put_carac(char format, va_list arg_point, int fd)
{
	int	len;

	len = ft_put_hexa(format, arg_point, fd);
	if (format == 'c')
		len = ft_putchar_printf(va_arg(arg_point, int), fd);
	else if (format == 's')
		len = ft_putstr_printf(va_arg(arg_point, char *), fd);
	else if (format == 'd' || format == 'i')
		len = ft_prep(va_arg(arg_point, int), fd, len, 10);
	else if (format == 'u')
		len = ft_prep(va_arg(arg_point, unsigned int), fd, len, 10);
	else if (format == '%')
		len = ft_putchar_printf('%', fd);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg_point;
	int		i;
	int		len_end;
	int		len;

	if (format == NULL)
		return (-1);
	len = ft_strlen(format);
	len_end = 0;
	i = 0;
	va_start (arg_point, format);
	while (i < len)
	{
		while (format[i] == '%' && format[i])
		{
			len_end += ft_put_carac(format[i + 1], arg_point, 1);
			i += 2;
		}
		if (format[i])
			len_end += ft_putchar_printf(format[i], 1);
		i++;
	}
	va_end(arg_point);
	return (len_end);
}
