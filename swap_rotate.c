/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzo <enzo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:26:54 by emagnani          #+#    #+#             */
/*   Updated: 2024/08/25 17:50:45 by enzo             ###   ########.fr       */
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

void	rotate(t_stack **stack, char abc)
{
	if (abc == 'a')
	{
		rotate_single(&((*stack)->a));
		ft_printf("ra\n");
	}
	if (abc == 'b')
	{
		rotate_single(&((*stack)->b));
		ft_printf("rb\n");
	}
	if (abc == 'c')
	{
		rotate_single(&((*stack)->a));
		rotate_single(&((*stack)->b));
		ft_printf("rr\n");
	}
}

void	rotate_single(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

// void	ra(t_stack **stack)
// {
// 	t_stack	*first;
// 	t_stack	*last;

// 	if (!(*stack) || !(*stack)->a || !(*stack)->a->next)
// 		return ;
// 	first = (*stack)->a;
// 	last = (*stack)->a;
// 	while (last->next)
// 		last = last->next;
// 	(*stack)->a = first->next;
// 	(*stack)->a->prev = NULL;
// 	last->next = first;
// 	first->prev = last;
// 	first->next = NULL;
// }

// void	rb(t_stack **stack)
// {
// 	t_stack	*first;
// 	t_stack	*last;

// 	if (!(*stack) || !(*stack)->b || !(*stack)->b->next)
// 		return ;
// 	first = (*stack)->b;
// 	last = (*stack)->b;
// 	while (last->next)
// 		last = last->next;
// 	(*stack)->b = first->next;
// 	(*stack)->b->prev = NULL;
// 	last->next = first;
// 	first->prev = last;
// 	first->next = NULL;
// }
