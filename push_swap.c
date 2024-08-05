/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzo <enzo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:21:33 by enzo              #+#    #+#             */
/*   Updated: 2024/08/04 14:15:09 by enzo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* int	check_repeating_digits(char *s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		if (s[i] != '\0')
			return (0);
		j = (i + 1);
		while (s[i] && s[i][ != s[j][0])
			j++;
		if (s[i][0] == s[j][0])
			return (0);
		else
			i++;
	}
	return (1);
} */

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
				exit_and_print_errors("error: + or - alone");
			j++;
		}
		while (array[i][j])
		{
			if (ft_isdigit(array[i][j]) || ft_isspace(array[i][j]))
				j++;
			else
				exit_and_print_errors("error: non-numerical character");
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

/* int	parsing(char *inputs)
{
	char	**split_inputs;

	split_inputs = ft_split(inputs, ' ');


	if (!check_repeating_digits(split_inputs))
		return (0);
	else
		return (1);
} */

void	value_to_list(t_stack **stack_a, long value)
{
	t_stack	*new_node;
	t_stack	*current;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		new_node = ft_free_null(new_node);
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
	// verify_list(stack_a);
	return (0);
}
