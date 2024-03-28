/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 10:19:59 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/03/25 21:37:00 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_game	engine;

	check_arg(ac, av[1]);
	build_map(av[1], &engine);
	build_mlx_win(&engine);
	build_mlx_images(engine);
	mlx_hook(engine.win_ptr, 2, 1, handle_input, &engine);
	mlx_loop_hook(engine.mlx_ptr, handle_loop_input, &engine);
	mlx_loop(engine.mlx_ptr);
	return (860);
}
