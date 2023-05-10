/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:42:18 by jduval            #+#    #+#             */
/*   Updated: 2023/04/01 11:55:16 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_count(int n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len + 1);
}

static char	*ft_spe_cond(int n)
{
	char	*s;

	if (n == -2147483648)
	{
		s = ft_strdup("-2147483648");
		return (s);
	}
	if (n == 0)
	{
		s = ft_strdup("0");
		return (s);
	}
	return (NULL);
}

static void	ft_fill(char *s, int n, int len, int start)
{
	len--;
	if (start == 1)
		s[0] = '-';
	while (len > start)
	{
		s[len - 1] = (n % 10) + '0';
		n /= 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	int		len;
	int		start;
	char	*s;

	start = 0;
	if (n == -2147483648 || n == 0)
		return (ft_spe_cond(n));
	if (n < 0)
	{
		start = 1;
		n *= (-1);
	}
	len = ft_count(n);
	if (start == 1)
	{
		len += start;
		s = malloc(sizeof(char) * len);
	}
	else
		s = malloc(sizeof(char) * len);
	if (!s)
		return (NULL);
	ft_fill(s, n, len, start);
	s[len - 1] = '\0';
	return (s);
}
