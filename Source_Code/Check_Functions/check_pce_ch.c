/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pce_ch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:15:19 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/03/21 15:15:22 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	check_characters(t_game *engine)
{
	int	row;
	int	col;

	row = -1;
	while (engine->map.map[++row])
	{
		col = 0;
		while (engine->map.map[row][col])
		{
			if (!ft_strchr("X01PCE", engine->map.map[row][col]))
			{
				err_characters(engine, engine->map.map[row][col]);
			}
			col++;
		}
	}
}

static void	check_collectable(t_game *engine)
{
	int	row;
	int	col;

	row = 1;
	engine->map.collec = 0;
	while (engine->map.map[row])
	{
		col = 1;
		while (col < engine->map.col - 1)
		{
			if (engine->map.map[row][col] == COLLEC)
				engine->map.collec++;
			col++;
		}
		row++;
	}
	if (!engine->map.collec)
		err_collec(engine);
}

static void	check_player(t_game *engine)
{
	int	row;
	int	col;
	int	player;

	player = 0;
	row = 0;
	while (++row < engine->map.row - 1)
	{
		col = 0;
		while (++col < engine->map.col - 1)
		{
			if (engine->map.map[row][col] == PLAYER)
			{
				player++;
				engine->player.x = row;
				engine->player.y = col;
			}
		}
	}
	if (player > 1 || !player)
		err_player(engine, player, "you must have 1 player but you have");
}

static void	check_exit(t_game *engine)
{
	int	row;
	int	col;
	int	exit;

	exit = 0;
	row = 1;
	while (engine->map.map[row])
	{
		col = 1;
		while (col < engine->map.col - 1)
		{
			if (engine->map.map[row][col] == EXIT)
			{
				exit++;
			}
			col++;
		}
		row++;
	}
	if (exit > 1 || !exit)
		err_exit(engine, exit, "you must have 1 exit but you have:");
}

void	check_pce(t_game *engine)
{
	check_player(engine);
	check_collectable(engine);
	check_exit(engine);
}
