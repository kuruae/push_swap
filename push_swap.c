/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagnani <emagnani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:07:02 by emagnani          #+#    #+#             */
/*   Updated: 2024/07/24 21:13:36 by emagnani         ###   ########.fr       */
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
	new_node->value = NULL;
	new_node->prev = NULL;
	
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
	if (argc == 1 || !argv[1][0])
		exit_and_print_errors("invalid input: not enough arguments");
	else if (argc == 2)
		array = str_args(argv[1]);
	else if (argc > 2)
		(void)argv;
	convert_and_append(array);
	return (0);
}
