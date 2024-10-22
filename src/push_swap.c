/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagnani <emagnani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:21:33 by enzo              #+#    #+#             */
/*   Updated: 2024/10/22 18:14:50 by emagnani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_and_print_errors(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	print_stack(t_stack *stack)
{
	long	nbr;

	while (stack)
	{
		nbr = stack->value;
		ft_printf("%d\n", nbr);
		stack = stack->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack		stacks;
	char		**array;
	bool		should_free;

	should_free = false;
	init_stacks(&stacks);
	array = NULL;
	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		if (!argv[1][0])
			exit_and_print_errors();
		should_free = true;
		array = str_args(argv[1]);
	}
	else if (argc > 2)
		array = multiple_args(argv);
	convert_and_append(&stacks, array, should_free);
	if (verify_repeating(stacks.a))
		start_sorting(&stacks);
	if (should_free)
		ft_free_str_array(&array);
	clear_stacks(&stacks);
	return (0);
}
