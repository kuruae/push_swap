/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzo <enzo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:21:33 by enzo              #+#    #+#             */
/*   Updated: 2024/08/13 15:59:40 by enzo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_and_print_errors(char *string)
{
	printf("%s\n", string);
	exit(1);
}

void	are_characters_valid(char **array)
{
	int	i;
	int	j;

	i = 0;
	while (array[i])
	{
		j = 0;
		if (array[i][j] == '+' || array[i][j] == '-')
		{
			if (!array[i][j + 1])
			{
				ft_free_str_array(&array);
				exit_and_print_errors("error: + or - alone");
			}
			j++;
		}
		while (array[i][j])
		{
			if (ft_isdigit(array[i][j]) || ft_isspace(array[i][j]))
				j++;
			else
			{
				ft_free_str_array(&array);
				exit_and_print_errors("error: non-numerical character");
			}
		}
		i++;
	}
}

char	**str_args(char *str)
{
	char	**array;

	array = ft_split(str, ' ');
	are_characters_valid(array);
	printf("the string is valid\n");
	return (array);
}

char	**multiple_args(char **array)
{
	are_characters_valid(array + 1);
	printf("the string is valid\n");
	return (array + 1);
}

void	value_to_list(t_stack **stack_a, long value)
{
	t_stack	*new_node;
	t_stack	*current;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
	{
		free(new_node);
		return ;
	}
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (!*stack_a)
		*stack_a = new_node;
	else
	{
		current = *stack_a;
		while (current->next)
			current = current->next;
		current->next = new_node;
		new_node->prev = current;
	}
	printf("node appended to stack a\n");
}

void	convert_and_append(t_stack **stack_a, char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		value_to_list(stack_a, ft_atol(array[i]));
		i++;
	}
}

void	verify_repeating(t_stack *stack)
{
	t_stack	*compare;

	while (stack)
	{
		compare = stack->next;
		while (compare)
		{
			if (stack->value == compare->value)
			{
				stack_clear(&stack);
				exit_and_print_errors("ERROR: repeating numbers entered.");
			}
			compare = compare->next;
		}
		stack = stack->next;
	}
	printf("No repeating.\n");
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	// t_stack	*stack_b;
	char	**array;

	stack_a = NULL;
	// stack_b = NULL;
	array = NULL;
	if (argc == 1 || !argv[1][0])
		exit_and_print_errors("invalid input: not enough arguments");
	else if (argc == 2)
		array = str_args(argv[1]);
	else if (argc > 2)
		array = multiple_args(argv);
	convert_and_append(&stack_a, array);
	verify_repeating(stack_a);
	// start_sorting(stack_a, stack_b);
	stack_clear(&stack_a);
	return (0);
}
