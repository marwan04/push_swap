/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malrifai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:38:04 by malrifai          #+#    #+#             */
/*   Updated: 2024/08/30 17:07:56 by malrifai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	cr;

	i = ft_strlen(s);
	cr = (unsigned char) c;
	if (cr == 0)
		return ((char *)s + i);
	while (i >= 0)
	{
		if (s[i] == cr)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
