/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagnani <emagnani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:07:07 by emagnani          #+#    #+#             */
/*   Updated: 2024/09/14 13:14:18 by emagnani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/libft.h"
# include "libft/includes/ft_printf.h"
# include <stdbool.h>

typedef struct s_stack
{
	int				index;
	long			value;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*a;
	struct s_stack	*b;
}	t_stack;

void	exit_and_print_errors(void);
void	check_sign(char **array, int i, bool should_free);
void	are_characters_valid(char **array, bool should_free);
char	**str_args(char *str);
char	**multiple_args(char **array);
void	value_to_list(t_stack **stack_a, long value);
void	convert_and_append(t_stack *stacks, char **array, bool should_free);
t_stack	*create_node(int value);
bool	verify_repeating(t_stack *stack);
void	stack_clear(t_stack **stack);
void	start_sorting(t_stack *stack);
void	init_stacks(t_stack *stacks);
void	clear_stacks(t_stack *stacks);
void	swap(t_stack *stack, char abc);
void	push(t_stack **stack, char ab);
void	rotate(t_stack **stack, char abc);
void	pa(t_stack **stack);
void	pb(t_stack **stacks);
void	print_stack(t_stack *stack);
void	sort_3(t_stack **stack);
void	sort_5(t_stack *stacks);
void	rotate_single(t_stack **stack);
void	radix_sort(t_stack *stacks);
int		get_max_bits(t_stack *stack);
int		stack_size(t_stack *stack);
void	indexing(t_stack *stack);
void	reverse_rotate_single(t_stack **stack);
void	reverse_rotate(t_stack **stack, char abc);
bool	is_sorted(t_stack *stacks);
int		rotate_or_rev(t_stack *stack, t_stack *node);
void	find_min_and_rotate(t_stack *stacks);

#endif