/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malrifai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:04:57 by malrifai          #+#    #+#             */
/*   Updated: 2024/10/02 18:01:08 by malrifai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_tab(int argc, char **argv, int boolean)
{
	t_list	*tab;
	int		i;

	tab = malloc(sizeof(t_list) * (argc + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (i < argc - 1)
	{
		if (boolean == 1)
		{
			tab[i].num = ft_atoi(argv[i]);
			tab[i].flag = 1;
		}
		else
		{
			tab[i].num = 0;
			tab[i].flag = 0;
		}
		tab[i].index = i;
		i++;
	}
	tab[i].index = -1;
	return (tab);
}

t_list	get_min_stack(t_list *stack)
{
	int	start;
	int	end;
	int	min;

	start = get_start_stack(stack);
	end = get_end_stack(stack);
	min = stack[start].index;
	while (start <= end)
	{
		if (stack[start].num < stack[min].num)
			min = stack[start].index;
		start++;
	}
	return (stack[min]);
}

t_list	get_max_stack(t_list *stack, int treshold)
{
	int	start;
	int	end;
	int	max;

	start = get_start_stack(stack);
	end = get_end_stack(stack);
	max = -1;
	while (start <= end)
	{
		if (max == -1 || ((stack[start].num > stack[max].num || \
		stack[max].flag == -1) && (treshold == -1 || \
		stack[start].num < treshold)))
			max = stack[start].index;
		start++;
	}
	return (stack[max]);
}

t_list	get_min_above_tresh(t_list *stack, int treshold)
{
	int	start;
	int	end;
	int	min;

	start = get_start_stack(stack);
	end = get_end_stack(stack);
	min = -1;
	while (start <= end)
	{
		if (stack[start].num > treshold && \
		(min == -1 || stack[start].num < stack[min].num))
			min = stack[start].index;
		start++;
	}
	if (min == -1)
		return (get_min_stack(stack));
	return (stack[min]);
}

int	is_sorted(t_list *stack)
{
	int	i;

	i = 0;
	while (stack[i + 1].index != -1)
	{
		if (stack[i].num > stack[i + 1].num)
			return (-1);
		i++;
	}
	return (1);
}
