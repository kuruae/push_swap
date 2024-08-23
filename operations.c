/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzo <enzo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:26:54 by emagnani          #+#    #+#             */
/*   Updated: 2024/08/23 17:08:08 by enzo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, char abc)
{
	long	temp;

	if (!stack || !stack->next)
		return ;
	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
	if (abc == 'a')
		ft_printf("sa\n");
	else if (abc == 'b')
		ft_printf("sb\n");
	else if (abc == 'c')
		ft_printf("ss");
}
