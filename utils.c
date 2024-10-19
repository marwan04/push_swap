/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malrifai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 19:22:29 by malrifai          #+#    #+#             */
/*   Updated: 2024/10/07 19:56:17 by malrifai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int	get_start_stack(t_sawp_list *stack)
{
	int	first;

	first = 0;
	while (stack[first].flag != 1)
		first++;
	if (stack[first].index == -1)
		first--;
	return (first);
}

int	get_end_stack(t_sawp_list *stack)
{
	int	end;

	end = 0;
	while (stack[end].index != -1)
		end++;
	end--;
	return (end);
}

int	is_median(t_sawp_list *stack, int num)
{
	int	start;
	int	end;
	int	higher;
	int	lower;

	start = get_start_stack(stack);
	end = get_end_stack(stack);
	higher = 0;
	lower = 0;
	while (start <= end)
	{
		if (stack[start].num > num)
			higher++;
		else if (stack[start].num < num)
			lower++;
		start++;
	}
	if ((higher - lower) >= -1 && (higher - lower) <= 1)
		return (1);
	return (0);
}
