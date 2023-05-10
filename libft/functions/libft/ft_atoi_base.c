/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:05:52 by jduval            #+#    #+#             */
/*   Updated: 2023/04/01 11:50:45 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_base(char c, int len)
{
	char	*base1;
	char	*base2;
	int		i;	

	i = 0;
	base1 = "0123456789ABCDEF";
	base2 = "0123456789abcdef";
	while (i < len)
	{
		if (c == base1[i] || c == base2[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, int str_base)
{
	int	i;
	int	value;
	int	a;

	value = 0;
	i = 0;
	a = 1;
	while (str[i] == ' ' || (str[i] == '\t' && str[i] == '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			a = -1;
		i++;
	}
	while (ft_base(str[i], str_base) != -1)
	{
		value = value * str_base;
		value += ft_base(str[i], str_base);
		i++;
	}
	return (value * a);
}
