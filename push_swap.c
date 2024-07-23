/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagnani <emagnani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:07:02 by emagnani          #+#    #+#             */
/*   Updated: 2024/07/23 21:17:23 by emagnani         ###   ########.fr       */
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
		if (ft_isdigit(str[i]) || ft_isspace(str[i]) || str[i] == 43)
			i++;
		else
			exit_and_print_errors("invalid inputs: non-numerical character");
	}
}

void	str_args(char *str)
{
	are_characters_valid(str);
	printf("the string is valid");
	// if (check_repeating_digits(str)

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

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || !argv[1][0])
		exit_and_print_errors("invalid input: not enough arguments");
	else if (argc == 2)
		str_args(argv[1]);
	// else if (!parsing(argv[1]))
	// 	ft_printf("invalid input: wrong format or repeating numbers.");
	else
		ft_printf("good!");
	return (0);
}
