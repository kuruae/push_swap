/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzo <enzo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:51:14 by enzo              #+#    #+#             */
/*   Updated: 2024/08/27 21:53:32 by enzo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **stacks)
{
	t_stack	*tmp;

	if ((*stacks)->b)
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
}

void	pb(t_stack **stacks)
{
	t_stack	*tmp;

	if ((*stacks)->a)
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

void	push(t_stack **stacks, char ab)
{
	if (ab == 'a')
		pa(stacks);
	else if (ab == 'b')
		pb(stacks);
}
