/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofernan <jofernan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 23:38:40 by jofernan          #+#    #+#             */
/*   Updated: 2022/05/24 01:22:27 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_int(char *str, double *number, double *neg)
{
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*neg = -1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		*number = *number * 10 + (*str - 48);
		str++;
	}
	return (str);
}

double	ft_atod(char *str)
{
	double	number;
	double	den;
	double	neg;

	neg = 1;
	den = 10;
	number = 0;
	if (!str)
		return (0);
	str = get_int(str, &number, &neg);
	if (*str == '.')
		str++;
	else
		return (number * neg);
	while (*str && (*str >= '0' && *str <= '9'))
	{
		number += (*str - 48) / den;
		den *= 10;
		str++;
	}
	return (number * neg);
}
