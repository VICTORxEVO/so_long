/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_mlx_images.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:11:47 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/03/26 14:03:20 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	render_images(t_game engine, char c, int y, int x)
{
	if (c == WALL)
		mlx_put_image_to_window(engine.mlx_ptr, engine.win_ptr, engine.img.wall,
			y * CONST, x * CONST);
	else if (c == FLOOR)
		mlx_put_image_to_window(engine.mlx_ptr, engine.win_ptr,
			engine.img.floor, y * CONST, x * CONST);
	else if (c == ENEMY)
		mlx_put_image_to_window(engine.mlx_ptr, engine.win_ptr,
			engine.img.enemy, y * CONST, x * CONST);
	else if (c == COLLEC)
		mlx_put_image_to_window(engine.mlx_ptr, engine.win_ptr,
			engine.img.collec, y * CONST, x * CONST);
	else if (c == PLAYER)
		mlx_put_image_to_window(engine.mlx_ptr, engine.win_ptr, engine.img.p0, y
			* CONST, x * CONST);
	else if (c == EXIT && !engine.map.collec)
		mlx_put_image_to_window(engine.mlx_ptr, engine.win_ptr,
			engine.img.exit_open, y * CONST, x * CONST);
	else if (c == EXIT && engine.map.collec)
		mlx_put_image_to_window(engine.mlx_ptr, engine.win_ptr,
			engine.img.exit_close, y * CONST, x * CONST);
}

static void	display_movement(t_game *engine)
{
	char	*move_str;

	move_str = ft_itoa(engine->player.mv_count);
	mlx_string_put(engine->mlx_ptr, engine->win_ptr, 19, 14, RED_WIN,
		"Moves: ");
	mlx_string_put(engine->mlx_ptr, engine->win_ptr, 57, 14, BOLD_WHITE,
		move_str);
	free(move_str);
	ft_printf("%s", CLEAR);
	ft_printf("so_long: %sMoves: %d%s\r", BRIGHT_YELLOW,
		engine->player.mv_count, END);
}

void	build_mlx_images(t_game engine)
{
	int	col;
	int	row;

	row = -1;
	while (++row < engine.map.row)
	{
		col = -1;
		while (++col < engine.map.col)
			render_images(engine, engine.map.map[row][col], col, row);
	}
	display_movement(&engine);
}
