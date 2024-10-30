/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malrifai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 04:16:02 by malrifai          #+#    #+#             */
/*   Updated: 2024/10/17 04:16:44 by malrifai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_args_number(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc - 1)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
			{
				if (!(j == 0 && argv[i][j] == '-'))
					return (-1);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static int	is_space(char c)
{
	char	*str;

	str = "\t\n\v\f\r";
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

long long	ft_atoi_ps(char *str)
{
	long long int	ans;
	int				result;

	ans = 0;
	result = 1;
	while (is_space(*str))
		str++;
	if (*str == '-')
		result *= -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		ans = (ans * 10) + (*str - 48);
		str++;
	}
	return (result * ans);
}

int	is_duplicate_number(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc - 1)
		{
			if (ft_atoi_ps(argv[i]) > 2147483647
				|| ft_atoi_ps(argv[i]) < -2147483648
				|| ft_atoi_ps(argv[j]) > 2147483647
				|| ft_atoi_ps(argv[j]) < -2147483648)
				return (-1);
			if (ft_atoi_ps(argv[i]) == ft_atoi_ps(argv[j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_handle_errors(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	if (is_args_number(argc, argv) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	if (is_duplicate_number(argc, argv) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	return (1);
}
