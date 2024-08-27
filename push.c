/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzo <enzo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:51:14 by enzo              #+#    #+#             */
/*   Updated: 2024/08/27 18:24:47 by enzo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stacks, char ab)
{
	t_stack	*tmp;

	if (ab == 'a' && (*stacks)->b)
	{
		tmp = (*stacks)->b;
		(*stacks)->b = (*stacks)->b->next;
		if ((*stacks)->b)
			(*stacks)->b->prev = NULL;
		tmp->next = (*stacks)->a;
		if ((*stacks)->a)
			(*stacks)->a->prev = tmp;
		(*stacks)->a = tmp;
		ft_printf("pa\n");
	}
	else if (ab == 'b' && (*stacks)->a)
	{
		tmp = (*stacks)->a;
		(*stacks)->a = (*stacks)->a->next;
		if ((*stacks)->a)
			(*stacks)->a->prev = NULL;
		tmp->next = (*stacks)->b;
		if ((*stacks)->b)
			(*stacks)->b->prev = tmp;
		(*stacks)->b = tmp;
		ft_printf("pb\n");
	}
}