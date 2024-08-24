/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_to_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzo <enzo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:30:23 by enzo              #+#    #+#             */
/*   Updated: 2024/08/24 15:41:30 by enzo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *stack)
{
	pb(&stack);
	if (stack->a->value > stack->a->next->value)
		swap(stack->a, 'a');
	pa(&stack);
	if (stack->a->value > stack->a->next->value)
		swap(stack->a, 'a');
	
}