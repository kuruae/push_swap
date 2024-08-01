/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzo <enzo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:21:33 by enzo              #+#    #+#             */
/*   Updated: 2024/08/01 23:02:06 by enzo             ###   ########.fr       */
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

void	are_characters_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) || ft_isspace(str[i])
			|| str[i] == '+' || str[i] == '-')
			i++;
		else
			exit_and_print_errors("invalid inputs: non-numerical character");
	}
}

char	**str_args(char *str)
{
	char	**array;

	are_characters_valid(str);
	printf("the string is valid");
	array = ft_split(str, ' ');
	return (array);

}

char	**multiple_args(char **array)
{
	int	i;

	i = 1;
	while (array[i])
	{
		are_characters_valid(array[i]);
		i++;
	}
	printf("the string is valid");
	return (array);
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

void	value_to_list(long value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		new_node = ft_free_null(new_node);

	new_node->value = value;
	new_node->value = 0;
	new_node->prev = 0;

}

void	convert_and_append(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		value_to_list(ft_atol(array[i]));
		i++;
	}
}


int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**array;

	stack_a = NULL;
	stack_b = NULL;
	array = NULL;
	if (argc == 1 || !argv[1][0])
		exit_and_print_errors("invalid input: not enough arguments");
	else if (argc == 2)
		array = str_args(argv[1]);
	else if (argc > 2)
		array = multiple_args(argv);
	convert_and_append(array);
	return (0);
}
