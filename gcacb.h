/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gcacb.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostano <abostano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:20:51 by abostano          #+#    #+#             */
/*   Updated: 2024/07/01 18:41:14 by abostano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GCACB_H
# define GCACB_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_gc
{
	size_t			number;
	void			*allocated;
	struct s_gc		*prev;
	struct s_gc		*next;
}				t_gc;

void	*ft_memset(void *str, int x, size_t a);
t_gc	*gc_init(void);
void	*gc_malloc(t_gc *head, size_t size);
void	*gc_calloc(t_gc *head, size_t nmemb, size_t size);
int		gc_free(t_gc *head, void *alloc);
void	gc_collect(t_gc *head);

#endif
