/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzo <enzo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:30:18 by enzo              #+#    #+#             */
/*   Updated: 2024/08/23 15:10:12 by enzo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_sorting(t_stack *stacks)
{
	if (ft_lstsize((t_list *)stacks->a) == 2)
	{
		if (stacks->a->value > stacks->a->next->value)
			swap(stacks->a, 'a');
	}
	return ;
	// else if (ft_lstsize((t_list *)stack.a) == 3)
	// 	sort_three(stack_a, stack_b);
	// else if (ft_lstsize((t_list *)stack.a) == 5)
	// 	sort_five();
	// else if (ft_lstsize((t_list *)stack.a) > 5)
	}
