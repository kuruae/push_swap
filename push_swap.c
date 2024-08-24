/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagnani <emagnani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:21:33 by enzo              #+#    #+#             */
/*   Updated: 2024/08/24 19:58:49 by emagnani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_and_print_errors(char *string)
{
	ft_printf("%s\n", string);
	exit(1);
}

void	are_characters_valid(char **array, bool should_free)
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
				if (should_free)
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
				if (should_free)
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
	are_characters_valid(array, true);
	ft_printf("the string is valid\n");
	return (array);
}

char	**multiple_args(char **array)
{
	are_characters_valid(array + 1, false);
	ft_printf("the string is valid\n");
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
	ft_printf("node appended to stack a\n");
}

void	convert_and_append(t_stack *stacks, char **array)
{
	int		i;
	long	n;

	i = 0;
	while (array[i])
	{
		n = ft_atol(array[i]);
		if (n > INT_MAX || n < INT_MIN)
			exit_and_print_errors("fdp");
		i++;
	}
	i = 0;
	while (array[i])
	{
		value_to_list(&(stacks->a), ft_atol(array[i]));
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
	ft_printf("No repeating.\n");
}

int	main(int argc, char **argv)
{
	t_stack		stacks;
	char		**array;
	bool		should_free;

	should_free = false;
	init_stacks(&stacks);
	array = NULL;
	if (argc == 1 || !argv[1][0])
		exit_and_print_errors("invalid input: not enough arguments");
	else if (argc == 2)
	{
		should_free = true;
		array = str_args(argv[1]);
	}
	else if (argc > 2)
		array = multiple_args(argv);
	convert_and_append(&stacks, array);
	verify_repeating(stacks.a);
	print_stack(stacks.a);
	start_sorting(&stacks);
	if (should_free)
		ft_free_str_array(&array);
	clear_stacks(&stacks);
	return (0);
}
