/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_to_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzo <enzo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:30:23 by enzo              #+#    #+#             */
/*   Updated: 2024/08/30 11:49:45 by enzo             ###   ########.fr       */
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

int	rotate_or_rev(t_stack *stack, t_stack *node)
{
	int		i;
	int		size;
	t_stack	*current;

	i = 0;
	size = stack_size(stack);
	current = stack;
	while (current != node)
	{
		current = current->next;
		i++;
	}
	if (size / 2 > i)
		return (1);
	return (2);
}

void	sort_5(t_stack *stacks)
{
	t_stack	*min;
	t_stack	*current;
	int		rotation;

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
		rotation = rotate_or_rev(stacks->a, min);
		while (stacks->a != min)
		{
			if (rotation == 1)
				rotate(&stacks, 'a');
			else
				reverse_rotate(&stacks, 'a');
		}
		push(&stacks, 'b');
	}
	sort_3(&stacks);
	while (stacks->b)
		push(&stacks, 'a');
}
