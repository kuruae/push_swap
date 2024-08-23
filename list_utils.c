/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzo <enzo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:22:36 by emagnani          #+#    #+#             */
/*   Updated: 2024/08/23 15:05:39 by enzo             ###   ########.fr       */
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

void	init_stacks(t_stack *stacks)
{
	stacks->a = NULL;
	stacks->b = NULL;
}

void	clear_stacks(t_stack *stacks)
{
	stack_clear(&stacks->a);
	stack_clear(&stacks->b);
}

void	print_stack(t_stack *stack)
{
	long	nbr;

	while (stack)
	{
		nbr = stack->value;
		ft_printf("%d\n", nbr);
		stack = stack->next;
	}
}

