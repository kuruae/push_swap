/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzo <enzo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:22:36 by emagnani          #+#    #+#             */
/*   Updated: 2024/08/01 18:44:51 by enzo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack) * 1);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_stack	*split_list(t_stack *head)
{
	t_stack	*fast;
	t_stack	*slow;
	t_stack	*second_half;

	fast = head;
	slow = head;
	if (head == NULL || head->next == NULL)
		return (NULL);
	while (fast->next && fast->next->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	second_half = slow->next;
	slow->next = NULL;
	if (second_half)
		second_half->prev = NULL;

	return (second_half);
}