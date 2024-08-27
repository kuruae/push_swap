/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzo <enzo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:51:14 by enzo              #+#    #+#             */
/*   Updated: 2024/08/26 16:38:41 by enzo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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