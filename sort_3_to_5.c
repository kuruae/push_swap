/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_to_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzo <enzo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:30:23 by enzo              #+#    #+#             */
/*   Updated: 2024/08/27 02:13:23 by enzo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **stack)
{
	push(&*stack, 'b');
	if ((*stack)->a->value > (*stack)->a->next->value)
		swap((*stack)->a, 'a');
	push(&*stack, 'a');
	if ((*stack)->a->value > (*stack)->a->next->next->value)
		rotate(stack, 'a');
	if ((*stack)->a->value > (*stack)->a->next->value)
		swap((*stack)->a, 'a');
}

void	sort_5(t_stack *stacks)
{
	t_stack	*min;
	t_stack	*current;

	while (stack_size(stacks->a) > 3)
	{
		min = stacks->a;
		current = stacks->a;
		while (current)
		{
			if (current->value < min->value)
				min = current;
			current = current->next;
		}
		while (stacks->a != min)
			rotate(&stacks, 'a');
		push(&stacks, 'b');
	}
	sort_3(&stacks);
	while (stacks->b)
		push(&stacks, 'a');
}
