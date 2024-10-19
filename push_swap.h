/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malrifai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:03:37 by malrifai          #+#    #+#             */
/*   Updated: 2024/10/19 16:24:49 by malrifai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct s_sawp_list
{
	int		num;
	int		flag;
	int		index;
}			t_sawp_list;

int			ft_handle_errors(int argc, char **argv);
void		push_stack(t_sawp_list *stack_a, t_sawp_list *stack_b, char *str);
void		shift_up(t_sawp_list *stack, char *str);
void		shift_down(t_sawp_list *stack, char *str);
t_sawp_list	*create_tab(int argc, char **argv, int boolean);
void		resolve_stack(t_sawp_list *stack_a, t_sawp_list *stack_b,
				int stack_size);
void		show_stack(t_sawp_list *stack_a, t_sawp_list *stack_b,
				int stack_size);
int			get_start_stack(t_sawp_list *stack);
int			get_end_stack(t_sawp_list *stack);
t_sawp_list	get_max_stack(t_sawp_list *stack, int treshold);
t_sawp_list	get_min_stack(t_sawp_list *stack);
int			get_op_for_topplace(t_sawp_list *stack_a, int index, int reel);
int			get_op_for_gplace(t_sawp_list *stack_a, t_sawp_list *stack_b,
				int index);
void		resolve_three(t_sawp_list *stack);
void		ft_swap(t_sawp_list *stack, char *msg);
t_sawp_list	get_min_above_tresh(t_sawp_list *stack, int treshold);
void		ft_double_shift(t_sawp_list *stack_a, t_sawp_list *stack_b,
				int down_up);
int			get_coherences(t_sawp_list *stack_a, t_sawp_list *stack_b,
				int index);
int			max(int a, int b);
int			min(int a, int b);
int			get_best_op_index(t_sawp_list *stack_a, t_sawp_list *stack_b,
				int stack_size);
int			is_sorted(t_sawp_list *stack);
int			is_median(t_sawp_list *stack, int num);
long long	ft_atoi_ps(char *str);

#endif
