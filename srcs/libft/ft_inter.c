/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofernan <jofernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 12:58:24 by jofernan          #+#    #+#             */
/*   Updated: 2022/05/06 21:21:50 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_dups(char *str, char c, int i, int read_full)
{
	int	j;

	j = 0;
	while ((j < i || read_full) && str[j])
		if (str[j++] == c)
			return (1);
	return (0);
}

int	ft_inter(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 3)
	{
		while (argv[1][i])
		{
			if (!ft_dups(argv[1], argv[1][i], i, 0))
				if (ft_dups(argv[2], argv[1][i], i, 1))
					write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
