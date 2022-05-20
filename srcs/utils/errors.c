/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofernan <jofernan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 23:39:11 by jofernan          #+#    #+#             */
/*   Updated: 2022/05/20 23:55:19 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include <stdio.h>

int	ft_argvcheck(char *argv)
{
	char	*s;

	s = ft_substr(argv, ft_strlen(argv) - 3, 3);
	if (ft_strncmp(s, ".rt", 3) || ft_strlen(argv) == 3)
	{
		free(s);
		return (1);
	}
	else
	{
		free(s);
		return (0);
	}
}

int	ft_argc(void)
{
	printf(BHRED "Error\nProgram cannot be executed like that\n" CLOSE);
	printf(BOLD "use=>./miniRT *.rt\n" CLOSE);
	return (1);
}

int	ft_error(char *s, t_rt *rt)
{
	printf(BHRED "Error\n%s\n" CLOSE, s);
	if (rt)
		free_struct(rt);
	return (1);
}
