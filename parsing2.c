/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzo <enzo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 01:54:30 by enzo              #+#    #+#             */
/*   Updated: 2024/08/27 03:21:48 by enzo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	value_to_list(t_stack **stack_a, long value)
{
	t_stack	*new_node;
	t_stack	*current;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
	{
		free(new_node);
		return ;
	}
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (!*stack_a)
		*stack_a = new_node;
	else
	{
		current = *stack_a;
		while (current->next)
			current = current->next;
		current->next = new_node;
		new_node->prev = current;
	}
}

void	convert_and_append(t_stack *stacks, char **array)
{
	int		i;
	long	n;

	i = 0;
	while (array[i])
	{
		n = ft_atol(array[i]);
		if (n > INT_MAX || n < INT_MIN)
			exit_and_print_errors("fdp");
		i++;
	}
	i = 0;
	while (array[i])
	{
		value_to_list(&(stacks->a), ft_atol(array[i]));
		i++;
	}
}

void	verify_repeating(t_stack *stack)
{
	t_stack	*compare;

	while (stack)
	{
		compare = stack->next;
		while (compare)
		{
			if (stack->value == compare->value)
			{
				stack_clear(&stack);
				exit_and_print_errors("ERROR: repeating numbers entered.");
			}
			compare = compare->next;
		}
		stack = stack->next;
	}
}