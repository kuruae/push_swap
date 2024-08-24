/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzo <enzo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:26:54 by emagnani          #+#    #+#             */
/*   Updated: 2024/08/24 15:31:01 by enzo             ###   ########.fr       */
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

void	pa(t_stack **stack, char ab)
{
	long	temp;
	t_stack	*del;
	t_stack	*new;

	if (!(*stack)->b)
		return ;
	temp = (*stack)->b->value;
	del = (*stack)->b;
	(*stack)->b = (*stack)->b->next;
	if (!(*stack)->b)
		(*stack)->b->prev = NULL;
	free(del);
	new = malloc(sizeof(t_stack));
	if (!new)
	{
		free(new);
		new = NULL;
		return ;
	}
	new->value = temp;
	new->next = (*stack)->a;
	new->prev = NULL;
	if (!(*stack)->a)
		(*stack)->a->prev = new;
	(*stack)->a = new;
}

void	pb(t_stack **stack, char ab)
{
	long	temp;
	t_stack	*del;
	t_stack	*new;

	if (!(*stack)->a)
		return ;
	temp = (*stack)->a->value;
	del = (*stack)->a;
	(*stack)->a = (*stack)->a->next;
	if (!(*stack)->a)
		(*stack)->a->prev = NULL;
	free(del);
	new = malloc(sizeof(t_stack));
	if (!new)
	{
		free(new);
		new = NULL;
		return ;
	}
	new->value = temp;
	new->next = (*stack)->b;
	new->prev = NULL;
	if (!(*stack)->b)
		(*stack)->b->prev = new;
	(*stack)->b = new;
}
