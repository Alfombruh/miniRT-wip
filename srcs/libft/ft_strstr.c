/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofernan <jofernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 12:58:24 by jofernan          #+#    #+#             */
/*   Updated: 2022/05/06 21:19:20 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	char	*a;
	char	*b;

	b = (char *)to_find;
	if (!*b)
	{
		return ((char *)str);
	}
	while (*str)
	{
		if (*str != *b)
		{
			str++;
			continue ;
		}
		a = (char *)str;
		while (*a++ == *b++)
		{
			if (!*b)
				return ((char *)str);
		}
		b = (char *)to_find;
		str++;
	}
	return (NULL);
}
