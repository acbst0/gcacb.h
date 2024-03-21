/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_funcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostano <abostano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:22:40 by abostano          #+#    #+#             */
/*   Updated: 2024/03/21 11:23:36 by abostano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gcacb.h"

void	*gc_init(void)
{
	t_gc	**gc;
	void	*ptr;

	gc = (t_gc **)malloc(sizeof(t_gc *));
	*gc = NULL;
	ptr = gc;
	return (ptr);
}

void	*gc_malloc(size_t size, void *ptr)
{
	t_gc	**tmp;
	t_gc	*new;

	tmp = ptr;
	while (*tmp)
		tmp = &(*tmp)->next;
	new = (t_gc *)malloc(sizeof(t_gc));
	new->allocated = malloc(size);
	(*tmp)->next = new;
	return (new->allocated);
}

void	*gc_calloc(size_t count, size_t size, void *ptr)
{
	t_gc	**tmp;
	t_gc	*new;

	tmp = ptr;
	while (*tmp)
		tmp = &(*tmp)->next;
	new = (t_gc *)malloc(sizeof(t_gc));
	new->allocated = malloc(size * count);
	ft_memset(new->allocated, 0, size * count);
	(*tmp)->next = new;
	return (new->allocated);
}

void	gc_free(void *allocated, void *ptr)
{
	t_gc	**head;
	t_gc	*tmp;

	head = ptr;
	while (*head && (*head)->allocated != allocated)
	{
		tmp = *head;
		*head = (*head)->next;
	}
	tmp->next = (*head)->next;
	free((*head)->allocated);
	free(*head);
}

void	gc_collect(void *ptr)
{
	t_gc	**head;
	t_gc	*tmp;

	head = ptr;
	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp->allocated);
		free(tmp);
	}
	free(head);
}
