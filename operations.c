/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagnani <emagnani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:26:54 by emagnani          #+#    #+#             */
/*   Updated: 2024/08/22 14:38:19 by emagnani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, char a_or_b)
{
	t_stack	*temp;
	long	temp_value;

	temp = stack->a->next;
	temp_value = stack->a->value;
	stack->a->value = temp->value;
	temp->value = temp_value;

	if (stack->a->prev)
		stack->a->prev->next = temp;
	if (temp->next)
		temp->next->prev = stack->a;
}