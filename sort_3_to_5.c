/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_to_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzo <enzo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:30:23 by enzo              #+#    #+#             */
/*   Updated: 2024/08/29 16:56:26 by enzo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->a->value;
	b = (*stack)->a->next->value;
	c = (*stack)->a->next->next->value;

	if (a > b && b < c && a < c)
		swap((*stack)->a, 'a');
	else if (a > b && b > c)
	{
		swap((*stack)->a, 'a');
		reverse_rotate(stack, 'a');
	}
	else if (a > b && b < c && a > c)
		rotate(stack, 'a');
	else if (a < b && b > c && a < c)
	{
		swap((*stack)->a, 'a');
		rotate(stack, 'a');
	}
	else if (a < b && b > c && a > c)
		reverse_rotate(stack, 'a');
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
	if (stacks->a->value > stacks->a->next->value)
		swap(stacks->a, 'a');
}
