/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzo <enzo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:22:36 by emagnani          #+#    #+#             */
/*   Updated: 2024/08/13 16:29:48 by enzo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack) * 1);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	stack_clear(t_stack **stack)
{
	t_stack	*node;
	t_stack	*tmp;

	node = *stack;
	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	*stack = NULL;
}

// void	init_stacks(t_stacks *stacks)
// {
// 	stacks->stack_a = NULL;
// 	stacks->stack_b = NULL;
// }

// void	clear_stacks(t_stacks *stacks)
// {
// 	stack_clear(&stacks->stack_a);
// 	stack_clear(&stacks->stack_b);
// }
