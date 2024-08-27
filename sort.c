/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzo <enzo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:22:36 by emagnani          #+#    #+#             */
/*   Updated: 2024/08/27 18:29:14 by enzo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_sorting(t_stack *stacks)
{
	int	size;

	size = stack_size(stacks->a);
	indexing(stacks->a);
	if (size == 1)
		return ;
	if (size == 2)
	{
		if (stacks->a->value > stacks->a->next->value)
			swap(stacks->a, 'a');
	}
	else if (size == 3)
		sort_3(&stacks);
	else if (size <= 5)
		sort_5(stacks);
	else
		radix_sort(stacks);
	print_stack(stacks->a);
}

int	get_max_bits(t_stack *stack)
{
	int	max;
	int	max_bits;

	max = stack->index;
	max_bits = 0;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	indexing(t_stack *stack)
{
	t_stack	*current;
	t_stack	*compare;
	int		index;

	current = stack;
	while (current)
	{
		index = 0;
		compare = stack;
		while (compare)
		{
			if (compare->value < current->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

void	radix_sort(t_stack *stacks)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	size = stack_size(stacks->a);
	max_bits = get_max_bits(stacks->a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			if (((stacks->a->index >> i) & 1) == 1)
				rotate(&stacks, 'a');
			else
				push(&stacks, 'b');
		}
		while (stack_size(stacks->b) != 0)
			push(&stacks, 'a');
		i++;
	}
}