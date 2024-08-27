/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzo <enzo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:21:33 by enzo              #+#    #+#             */
/*   Updated: 2024/08/27 03:22:55 by enzo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_and_print_errors(char *string)
{
	ft_printf("%s\n", string);
	exit(1);
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
