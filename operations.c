/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malrifai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:06:07 by malrifai          #+#    #+#             */
/*   Updated: 2024/10/02 18:22:00 by malrifai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack(t_sawp_list *stack_a, t_sawp_list *stack_b, char *str)
{
	int	first;
	int	end;

	first = 0;
	while (stack_a[first].flag != 1)
		first++;
	end = 0;
	while (stack_b[end].index != -1 && stack_b[end].flag != 1)
		end++;
	end--;
	stack_b[end].num = stack_a[first].num;
	stack_a[first].num = 0;
	stack_b[end].flag = 1;
	stack_a[first].flag = 0;
	ft_putstr_fd(str, 1);
}

void	shift_up(t_sawp_list *stack, char *str)
{
	int	start;
	int	end;
	int	tempnum;
	int	tempnum2;
	int	i;

	start = 0;
	while (stack[start].index != -1 && stack[start].flag != 1)
		start++;
	end = 0;
	while (stack[end].index != -1)
		end++;
	end--;
	i = end;
	tempnum = stack[i].num;
	while (i > start)
	{
		tempnum2 = stack[i - 1].num;
		stack[i - 1].num = tempnum;
		tempnum = tempnum2;
		i--;
	}
	stack[end].num = tempnum;
	ft_putstr_fd(str, 1);
}

void	shift_down(t_sawp_list *stack, char *str)
{
	int	start;
	int	end;
	int	tempnum;
	int	tempnum2;
	int	i;

	start = 0;
	while (stack[start].index != -1 && stack[start].flag != 1)
		start++;
	end = 0;
	while (stack[end].index != -1)
		end++;
	end--;
	i = start;
	tempnum = stack[i].num;
	while (i < end)
	{
		tempnum2 = stack[i + 1].num;
		stack[i + 1].num = tempnum;
		tempnum = tempnum2;
		i++;
	}
	stack[start].num = tempnum;
	ft_putstr_fd(str, 1);
}

void	ft_swap(t_sawp_list *stack, char *msg)
{
	int	start;
	int	temp;

	start = get_start_stack(stack);
	temp = stack[start].num;
	stack[start].num = stack[start + 1].num;
	stack[start + 1].num = temp;
	ft_putstr_fd(msg, 1);
}

void	ft_double_shift(t_sawp_list *stack_a, t_sawp_list *stack_b, int down_up)
{
	if (down_up == 1)
	{
		shift_down(stack_a, "");
		shift_down(stack_b, "");
		ft_putstr_fd("rrr\n", 1);
	}
	else
	{
		shift_up(stack_a, "");
		shift_up(stack_b, "");
		ft_putstr_fd("rr\n", 1);
	}
}
