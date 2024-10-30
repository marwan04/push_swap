/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malrifai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:24:21 by malrifai          #+#    #+#             */
/*   Updated: 2024/10/23 23:55:20 by malrifai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	choose_resolve(t_sawp_list *stack_a, t_sawp_list *stack_b, int argc)
{
	if (argc == 3)
	{
		if (is_sorted(stack_a) == -1)
			ft_swap(stack_a, "sa\n");
	}
	else if (argc == 4)
		resolve_three(stack_a);
	else
		resolve_stack(stack_a, stack_b, argc);
}

int	args_len(char **split_args)
{
	int	i;

	i = 0;
	while (split_args[i])
		i++;
	return (i);
}

char	**split_args(int *argc, char **argv, int *tofree)
{
	char	**split_args;

	split_args = ft_split(argv[0], ' ');
	*argc = args_len(split_args) + 1;
	*tofree = 1;
	return (split_args);
}

void	ft_free(t_sawp_list *stack_a, t_sawp_list *stack_b,
		char **split_sawp_list, int tofree)
{
	int	i;

	if (tofree)
	{
		i = 0;
		while (split_sawp_list[i] != 0)
		{
			free(split_sawp_list[i]);
			i++;
		}
		free(split_sawp_list[i]);
		free(split_sawp_list);
	}
	if (stack_a != NULL)
		free(stack_a);
	if (stack_b != NULL)
		free(stack_b);
}
/*
void	print_stack(t_sawp_list *stack)
{
	int	i;

	i = 0;
	printf("Stack Contents:\n");
	while (stack[i].index != -1)
	{
		printf("Index: %d, Num: %d, Flag: %d\n", stack[i].index, stack[i].num,
			stack[i].flag);
		i++;
	}
}
*/

int	main(int argc, char **argv)
{
	int			error;
	t_sawp_list	*stack_a;
	t_sawp_list	*stack_b;
	char		**split_sawp_list;
	int			tofree;

	tofree = 0;
	argv++;
	split_sawp_list = argv;
	if (argc == 2)
		split_sawp_list = split_args(&argc, argv, &tofree);
	error = ft_handle_errors(argc, split_sawp_list);
	if (error == -1 || error == 0)
	{
		ft_free(NULL, NULL, split_sawp_list, tofree);
		return (0);
	}
	stack_a = create_tab(argc, split_sawp_list, 1);
	stack_b = create_tab(argc, split_sawp_list, 0);
	if (is_sorted(stack_a) == -1)
		choose_resolve(stack_a, stack_b, argc);
	ft_free(stack_a, stack_b, split_sawp_list, tofree);
	return (0);
}
