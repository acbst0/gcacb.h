/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostano <abostano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:24:11 by abostano          #+#    #+#             */
/*   Updated: 2024/02/27 20:12:37 by abostano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gcacb.h"

void	*ft_memset(void *str, int x, size_t a)
{
	size_t	i;
	char	*p;

	p = (char *)str;
	i = 0;
	while (i < a)
	{
		p[i] = x;
		i++;
	}
	return (p);
}

void	ft_lstadd_back(t_gc **lst, t_gc *new)
{
	t_gc	*tmp;

	tmp = *lst;
	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while (tmp -> next)
	{
		tmp = tmp -> next;
	}
	tmp->next = new;
}
