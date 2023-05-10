/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:20:49 by jduval            #+#    #+#             */
/*   Updated: 2023/05/10 13:39:05 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_putnbr_hex(unsigned int nbr, char c, int fd, int len)
{
	char	*base;

	len = ft_nbrlen(nbr, 16);
	if ((int)c == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (nbr > 15)
	{
		ft_putnbr_hex(nbr / 16, c, fd, len);
		ft_putnbr_hex(nbr % 16, c, fd, len);
	}
	if (nbr < 16)
		ft_putchar_printf(base[nbr % 16], fd);
	return (len);
}

int	ft_putstr_printf(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_putstr_printf("(null)", fd);
		return (6);
	}
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putchar_printf(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

static void	ft_putnbr_hex_p(long unsigned nbr, int fd)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr > 15)
	{
		ft_putnbr_hex_p(nbr / 16, fd);
		ft_putnbr_hex_p(nbr % 16, fd);
	}
	if (nbr < 16)
		ft_putchar_printf(base[nbr % 16], fd);
}

int	ft_print_p(long unsigned nbr, int fd, int len)
{
	if (nbr == 0)
	{
		len = ft_putstr_printf("(nil)", fd);
		return (len);
	}
	len = ft_putstr_printf("0x", fd);
	len += ft_nbrlen(nbr, 16);
	ft_putnbr_hex_p(nbr, fd);
	return (len);
}
