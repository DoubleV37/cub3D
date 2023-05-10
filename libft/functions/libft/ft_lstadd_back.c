/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:11:15 by jduval            #+#    #+#             */
/*   Updated: 2023/04/01 11:59:55 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *node)
{
	t_list	*p;

	if (!lst || !node)
		return ;
	if (!(*lst))
		*lst = node;
	else
	{
		p = ft_lstlast(*lst);
		p->next = node;
	}
	return ;
}
