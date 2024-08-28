/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzo <enzo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:26:54 by emagnani          #+#    #+#             */
/*   Updated: 2024/08/28 20:41:42 by enzo             ###   ########.fr       */
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
	if (abc == 'a' && (*stack)->a)
	{
		rotate_single(&((*stack)->a));
		ft_printf("ra\n");
	}
	if (abc == 'b' && (*stack)->b)
	{
		rotate_single(&((*stack)->b));
		ft_printf("rb\n");
	}
	if (abc == 'c' && (*stack)->a && (*stack)->b)
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

void	reverse_rotate(t_stack **stack, char abc)
{
	if (abc == 'a' && (*stack)->a)
	{
		rotate_single(&((*stack)->a));
		ft_printf("rra\n");
	}
	if (abc == 'b' && (*stack)->b)
	{
		rotate_single(&((*stack)->b));
		ft_printf("rrb\n");
	}
	if (abc == 'c' && (*stack)->a && (*stack)->b)
	{
		rotate_single(&((*stack)->a));
		rotate_single(&((*stack)->b));
		ft_printf("rrr\n");
	}
}

void	reverse_rotate_single(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*second_last;

	if (!*stack || !(*stack)->next)
		return ;

	first = *stack;
	last = *stack;
	second_last = NULL;

	while (last->next)
	{
		second_last = last;
		last = last->next;
	}

	*stack = last;
	(*stack)->prev = NULL;
	(*stack)->next = first;
	first->prev = *stack;
	second_last->next = NULL;
}
