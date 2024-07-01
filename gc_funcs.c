/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_funcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostano <abostano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:22:40 by abostano          #+#    #+#             */
/*   Updated: 2024/07/01 18:41:39 by abostano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gcacb.h"

t_gc	*gc_init(void)
{
	t_gc	*gc;

	gc = (t_gc *)malloc(sizeof(t_gc));
	if (!gc)
		return (NULL);
	gc->next = NULL;
	gc->allocated = NULL;
	gc->number = 0;
	gc->prev = NULL;
	return (gc);
}

void	*gc_malloc(t_gc *head, size_t size)
{
	t_gc	*tmp;
	t_gc	*tmp2;

	tmp2 = head;
	tmp = (t_gc *)malloc(sizeof(t_gc));
	if (!tmp)
		return (NULL);
	tmp->allocated = malloc(size);
	tmp->next = NULL;
	if (!tmp->allocated)
	{
		free(tmp);
		return (NULL);
	}
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	tmp->prev = tmp2;
	tmp->number = tmp2->number + 1;
	return (tmp->allocated);
}

void	*gc_calloc(t_gc *head, size_t nmemb, size_t size)
{
	t_gc	*tmp;
	t_gc	*tmp2;

	tmp2 = head;
	tmp = (t_gc *)malloc(sizeof(t_gc));
	if (!tmp)
		return (NULL);
	tmp->allocated = malloc(nmemb * size);
	tmp->next = NULL;
	if (!tmp->allocated)
	{
		free(tmp);
		return (NULL);
	}
	ft_memset(tmp->allocated, 0, nmemb * size);
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	tmp->prev = tmp2;
	tmp->number = tmp2->number + 1;
	return (tmp->allocated);
}

int	gc_free(t_gc *head, void *alloc)
{
	t_gc	*tmp;
	t_gc	*tmp2;

	tmp = head;
	while (tmp->next)
	{
		if (tmp->allocated == alloc)
		{
			tmp2 = tmp->prev;
			tmp2->next = tmp->next;
			if (tmp->next)
				tmp->next->prev = tmp2;
			else
				tmp->next->prev = NULL;
			free(tmp->allocated);
			free(tmp);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

void	gc_collect(t_gc *head)
{
	t_gc	*tmp;

	while (head->next)
	{
		head = head->next;
		tmp = head->prev;
		head->prev = NULL;
		free(tmp->allocated);
		free(tmp);
	}
	free(head->allocated);
	free(head);
}
