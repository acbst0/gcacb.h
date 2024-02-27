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

	gc = (t_gc *)malloc(sizeof(t_gc));
	gc->allocated = NULL;
	gc->next = NULL;
	return (gc);
}

void	*gc_malloc(size_t size, void *ptr)
{
	t_gc	*tmp;
	t_gc	*new;

	tmp = ptr;
	while (tmp->next)
		tmp = tmp->next;
	new = (t_gc *)malloc(sizeof(t_gc));
	tmp->next = new;
	new->allocated = malloc(size);
	return (tmp->allocated);
}

void	*gc_calloc(size_t count, size_t size, void *ptr)
{
	t_gc	*tmp;
	t_gc	*new;

	tmp = ptr;
	while (tmp->next)
		tmp = tmp->next;
	new = (t_gc *)malloc(sizeof(t_gc));
	tmp->next = new;
	new->allocated = malloc(size);
	ft_memset(new->allocated, 0, size);
	return (tmp->allocated);
}

void	gc_collect(void *ptr)
{
	
}