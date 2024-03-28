/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:18:35 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/03/25 21:39:49 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	ft_swap(t_game *engine, int i, int j)
{
	char	tmp;
	char	c;

	c = engine->map.map[engine->player.x + i][engine->player.y + j];
	tmp = engine->map.map[engine->player.x][engine->player.y];
	engine->map.map[engine->player.x][engine->player.y] = c;
	engine->map.map[engine->player.x + i][engine->player.y + j] = tmp;
}

static bool	destination(t_game *engine, int i, int j, char c)
{
	if (engine->map.map[engine->player.x + i][engine->player.y + j] == c)
		return (true);
	return (false);
}

static bool	handle_move(t_game *engine, int i, int j)
{
	if (destination(engine, i, j, FLOOR))
	{
		ft_swap(engine, i, j);
		engine->player.x += i;
		engine->player.y += j;
		engine->player.mv_count++;
	}
	else if (destination(engine, i, j, COLLEC))
	{
		ft_swap(engine, i, j);
		engine->map.map[engine->player.x][engine->player.y] = FLOOR;
		engine->player.x += i;
		engine->player.y += j;
		engine->map.collec--;
		engine->player.mv_count++;
	}
	else if (destination(engine, i, j, EXIT) && !engine->map.collec)
		shutdown_game_win(engine, "YOU WIN");
	else if (destination(engine, i, j, ENEMY))
		shutdown_game_win(engine, "YOU DIE");
	else
		return (false);
	return (true);
}

int	handle_input(int key, t_game *engine)
{
	bool	res;

	res = false;
	if (key == UP)
		res = handle_move(engine, -1, 0);
	else if (key == DOWN)
		res = handle_move(engine, 1, 0);
	else if (key == RIGHT)
		res = handle_move(engine, 0, 1);
	else if (key == LEFT)
		res = handle_move(engine, 0, -1);
	else if (key == ESC)
		shutdown_game_win(engine, "Game Exited Successfully");
	if (!res)
		return (0);
	mlx_clear_window(engine->mlx_ptr, engine->win_ptr);
	build_mlx_images(*engine);
	return (0);
}
