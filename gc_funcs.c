/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_funcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostano <abostano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:22:40 by abostano          #+#    #+#             */
/*   Updated: 2024/02/27 20:13:02 by abostano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gcacb.h"


void *gc_init(void)
{
	t_gc	*gc;
	void	*ptr;

	gc = (t_gc *)malloc(sizeof(t_gc));
	gc->allocated = NULL;
	gc->next = NULL;
	ptr = gc;
	return (ptr);
}

void	*gc_malloc(size_t size, void *ptr)
{
	t_gc	*tmp;
	t_gc	*new;

	tmp = ptr;
	while (tmp->next)
		tmp = tmp->next;
	new = (t_gc *)malloc(sizeof(t_gc));
	ft_lstadd_back(&tmp, new);
	new->allocated = malloc(size);
	return (new->allocated);
}

void	*gc_calloc(size_t count, size_t size, void *ptr)
{
	t_gc	*tmp;
	t_gc	*new;

	tmp = ptr;
	while (tmp->next)
		tmp = tmp->next;
	new = (t_gc *)malloc(sizeof(t_gc));
	ft_lstadd_back(&tmp, new);
	new->allocated = malloc(size * count);
	ft_memset(new->allocated, 0, size);
	return (new->allocated);
}

void	gc_free(void *ptr)
{
	t_gc	*tmp;
	t_gc	*tmp2;

	tmp = ptr;
	while (tmp)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		free(tmp2->allocated);
		free(tmp2);
	}
}

void	gc_collect(void *ptr)
{
	t_gc	*tmp;
	t_gc	*tmp2;

	tmp = ptr;
	while (tmp)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		free(tmp2->allocated);
		free(tmp2);
	}
}