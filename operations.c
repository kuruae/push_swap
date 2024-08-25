/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzo <enzo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:26:54 by emagnani          #+#    #+#             */
/*   Updated: 2024/08/25 17:13:12 by enzo             ###   ########.fr       */
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

void	push(t_stack **stack, char ab)
{
	if (ab == 'a')
	{
		pa(stack);
		ft_printf("pa\n");
	}
	if (ab == 'b')
	{
		pb(stack);
		ft_printf("pb\n");
	}
}

void	pa(t_stack **stack)
{
	long	temp;
	t_stack	*del;
	t_stack	*new;

	if (!(*stack)->b)
		return ;
	temp = (*stack)->b->value;
	del = (*stack)->b;
	(*stack)->b = (*stack)->b->next;
	if ((*stack)->b != NULL)
		(*stack)->b->prev = NULL;
	free(del);
	new = malloc(sizeof(t_stack));
	if (!new)
	{
		free(new);
		new = NULL;
	}
	new->value = temp;
	new->next = (*stack)->a;
	new->prev = NULL;
	if ((*stack)->a != NULL)
		(*stack)->a->prev = new;
	(*stack)->a = new;
}

void	pb(t_stack **stack)
{
	long	temp;
	t_stack	*del;
	t_stack	*new;

	if (!(*stack)->a)
		return ;
	temp = (*stack)->a->value;
	del = (*stack)->a;
	(*stack)->a = (*stack)->a->next;
	if ((*stack)->a != NULL)
		(*stack)->a->prev = NULL;
	free(del);
	new = malloc(sizeof(t_stack));
	if (!new)
	{
		free(new);
		new = NULL;
	}
	new->value = temp;
	new->next = (*stack)->b;
	new->prev = NULL;
	if ((*stack)->b != NULL)
		(*stack)->b->prev = new;
	(*stack)->b = new;
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
