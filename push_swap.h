/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagnani <emagnani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:07:07 by emagnani          #+#    #+#             */
/*   Updated: 2024/08/22 14:19:00 by emagnani         ###   ########.fr       */
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
	struct s_stack	*a;
	struct s_stack	*b;
}	t_stack;

void	exit_and_print_errors(char *string);
void	are_characters_valid(char **array, bool should_free);
char	**str_args(char *str);
char	**multiple_args(char **array);
void	value_to_list(t_stack **stack_a, long value);
void	convert_and_append(t_stack *stacks, char **array);
t_stack	*create_node(int value);
t_stack	*split_list(t_stack *head);
void	verify_repeating(t_stack *stack);
void	stack_clear(t_stack **stack);
void	start_sorting(t_stack *stack);
void	init_stacks(t_stack *stacks);
void	clear_stacks(t_stack *stacks);

#endif