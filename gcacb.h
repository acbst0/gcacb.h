/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gcacb.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostano <abostano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:20:51 by abostano          #+#    #+#             */
/*   Updated: 2024/03/21 11:22:41 by abostano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GCACB_H
# define GCACB_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_gc
{
	void			*allocated;
	struct s_list	*next;
}				t_gc;

void	*ft_memset(void *str, int x, size_t a);
void	*gc_init(void);
void	*gc_malloc(size_t size, void *ptr);
void	*gc_calloc(size_t count, size_t size, void *ptr);
void	gc_free(void *allocated, void *ptr);
void	gc_collect(void *ptr);

#endif
