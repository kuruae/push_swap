/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzo <enzo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:07:07 by emagnani          #+#    #+#             */
/*   Updated: 2024/08/03 16:40:32 by enzo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../../circle1/libft/includes/libft.h"
# include "../../circle1/libft/includes/ft_printf.h"

typedef struct s_stack
{
	long				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

void	exit_and_print_errors(char *string);
void	are_characters_valid(char **array);
char	**str_args(char *str);
void	value_to_list(t_stack **stack_a, long value);
void	convert_and_append(t_stack **stack_a, char **array);
t_stack	*create_node(int value);
t_stack	*split_list(t_stack *head);

#endif