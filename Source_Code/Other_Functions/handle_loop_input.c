/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_loop_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:18:50 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/03/23 17:45:10 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	handle_animation(t_game *engine)
{
	if (engine->player.animation == 0)
		engine->player.animation = 1;
	else if (engine->player.animation == 1)
		engine->player.animation = 2;
	else if (engine->player.animation == 2)
		engine->player.animation = 3;
	else if (engine->player.animation == 3)
		engine->player.animation = 4;
	else if (engine->player.animation == 4)
		engine->player.animation = 0;
}

static void	put_frame(t_game *engine, int y, int x, int a)
{
	if (a == 0)
		mlx_put_image_to_window(engine->mlx_ptr, engine->win_ptr,
			engine->img.p0, y * CONST, x * CONST);
	else if (a == 1)
		mlx_put_image_to_window(engine->mlx_ptr, engine->win_ptr,
			engine->img.p1, y * CONST, x * CONST);
	else if (a == 2)
		mlx_put_image_to_window(engine->mlx_ptr, engine->win_ptr,
			engine->img.p2, y * CONST, x * CONST);
	else if (a == 3)
		mlx_put_image_to_window(engine->mlx_ptr, engine->win_ptr,
			engine->img.p3, y * CONST, x * CONST);
	else if (a == 4)
		mlx_put_image_to_window(engine->mlx_ptr, engine->win_ptr,
			engine->img.p4, y * CONST, x * CONST);
}

int	handle_loop_input(t_game *engine)
{
	static int	counter;

	counter++;
	if (counter > ANIMATION_SPEED)
	{
		handle_animation(engine);
		put_frame(engine, engine->player.y, engine->player.x,
			engine->player.animation);
		counter = 0;
	}
	return (0);
}
