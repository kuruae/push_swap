/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzo <enzo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:07:07 by emagnani          #+#    #+#             */
/*   Updated: 2024/08/13 18:57:07 by enzo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../../circle1/libft/includes/libft.h"
# include "../../circle1/libft/includes/ft_printf.h"
# include <stdbool.h>

typedef struct s_stack
{
	long			value;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_stacks
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
}	t_stacks;

void	exit_and_print_errors(char *string);
void	are_characters_valid(char **array, bool should_free);
char	**str_args(char *str);
char	**multiple_args(char **array);
void	value_to_list(t_stack **stack_a, long value);
void	convert_and_append(t_stacks *stacks, char **array);
t_stack	*create_node(int value);
t_stack	*split_list(t_stack *head);
void	verify_repeating(t_stack *stack);
void	stack_clear(t_stack **stack);
void	start_sorting(t_stack *stack_a, t_stack *stack_b);
void	init_stacks(t_stacks *stacks);
void	clear_stacks(t_stacks *stacks);

#endif