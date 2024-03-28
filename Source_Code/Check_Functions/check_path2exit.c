/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path2exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:13:27 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/03/25 21:08:31 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	init_var(int *xd, int *yd, t_game *engine)
{
	int		i;
	size_t	total;

	i = -1;
	total = (engine->map.row) * (engine->map.col);
	xd[0] = -1;
	xd[1] = 1;
	xd[2] = 0;
	xd[3] = 0;
	yd[0] = 0;
	yd[1] = 0;
	yd[2] = 1;
	yd[3] = -1;
	engine->map.vmap = malloc(sizeof(bool *) * (engine->map.row + 1));
	if (!engine->map.vmap)
		err_malloc_v2("Memory allocation failed!", engine);
	engine->map.vmap[engine->map.row] = NULL;
	while (++i < engine->map.row)
	{
		engine->map.vmap[i] = malloc(sizeof(bool) * engine->map.col);
		if (!engine->map.vmap[i])
			err_malloc_v2("Memory allocation failed!", engine);
	}
	engine->stack = malloc(sizeof(t_position) * total);
	return (1);
}

static void	init_bool(t_game *engine)
{
	int	x;
	int	y;

	x = -1;
	while (++x < engine->map.row)
	{
		y = -1;
		while (++y < engine->map.col)
		{
			if (engine->map.map[x][y] == WALL)
				engine->map.vmap[x][y] = true;
			else if (engine->map.map[x][y] == ENEMY)
				engine->map.vmap[x][y] = true;
			else
				engine->map.vmap[x][y] = false;
		}
	}
	engine->map.vmap[engine->player.x][engine->player.y] = true;
}

static void	mark_true(t_game *engine, size_t *up)
{
	engine->stack[*up].x = engine->index.new_x;
	engine->stack[*up].y = engine->index.new_y;
	engine->map.vmap[engine->index.new_x][engine->index.new_y] = true;
	(*up)++;
}

static void	compare_maps(t_game *engine)
{
	int	x;
	int	y;

	x = -1;
	while (++x < engine->map.row)
	{
		y = -1;
		while (++y < engine->map.col)
		{
			if (engine->map.map[x][y] == EXIT && !engine->map.vmap[x][y])
				err_path2exit(engine);
		}
	}
	free_vmap(engine);
}

void	check_path2exit(t_game *engine)
{
	int		xd[4];
	int		yd[4];
	size_t	up;
	int		i;

	up = init_var(xd, yd, engine);
	init_bool(engine);
	engine->stack[0].x = engine->player.x;
	engine->stack[0].y = engine->player.y;
	while (up > 0)
	{
		up--;
		engine->index.curr_x = engine->stack[up].x;
		engine->index.curr_y = engine->stack[up].y;
		i = -1;
		while (++i < 4)
		{
			engine->index.new_x = engine->index.curr_x + xd[i];
			engine->index.new_y = engine->index.curr_y + yd[i];
			if (!engine->map.vmap[engine->index.new_x][engine->index.new_y])
				mark_true(engine, &up);
		}
	}
	compare_maps(engine);
}
