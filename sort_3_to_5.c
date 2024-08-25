/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_to_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzo <enzo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:30:23 by enzo              #+#    #+#             */
/*   Updated: 2024/08/25 02:07:57 by enzo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **stack)
{
	push(&*stack, 'b');
	if ((*stack)->a->value > (*stack)->a->next->value)
		swap((*stack)->a, 'a');
	push(&*stack, 'a');
	// else if ((*stack)->a->value > (*stack)->a->next->next->value))
	// 	rotate((*stack)->a, 'a');
	if ((*stack)->a->value > (*stack)->a->next->value)
		swap((*stack)->a, 'a');
	ft_printf("sorted 3:\n");
	print_stack((*stack)->a);
}
