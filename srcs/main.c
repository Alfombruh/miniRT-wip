/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofernan <jofernan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 23:39:42 by jofernan          #+#    #+#             */
/*   Updated: 2022/05/20 23:40:29 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	main(int argc, char **argv)
{
	t_rt	rt;

	if (argc != 2)
		return (ft_argc());
	if (ft_argvcheck(argv[1]))
		return (ft_error("not .rt file", NULL));
	ft_memset(&rt, 0, sizeof(rt));
	if (ft_readrt(argv[1], &rt))
		return (ft_error(".rt file bad synstaxis", &rt));
	mlx_start(&rt);
	return (0);
}
