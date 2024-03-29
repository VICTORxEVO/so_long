/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_xpm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:22:09 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/03/29 17:22:13 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	check_xpm_part4(t_game *engine)
{
	if (!engine->img.p3)
		err_xpm(engine, "bad (player frame 4) xpm file!");
	else if (!engine->img.p4)
	{
		mlx_destroy_image(engine->mlx_ptr, engine->img.wall);
		mlx_destroy_image(engine->mlx_ptr, engine->img.floor);
		mlx_destroy_image(engine->mlx_ptr, engine->img.enemy);
		mlx_destroy_image(engine->mlx_ptr, engine->img.collec);
		mlx_destroy_image(engine->mlx_ptr, engine->img.exit_close);
		mlx_destroy_image(engine->mlx_ptr, engine->img.exit_open);
		mlx_destroy_image(engine->mlx_ptr, engine->img.p0);
		mlx_destroy_image(engine->mlx_ptr, engine->img.p1);
		mlx_destroy_image(engine->mlx_ptr, engine->img.p2);
		mlx_destroy_image(engine->mlx_ptr, engine->img.p3);
		err_xpm(engine, "bad (player frame 5) xpm file!");
	}
}

static void	check_xpm_part3(t_game *engine)
{
	if (!engine->img.p2)
	{
		mlx_destroy_image(engine->mlx_ptr, engine->img.wall);
		mlx_destroy_image(engine->mlx_ptr, engine->img.floor);
		mlx_destroy_image(engine->mlx_ptr, engine->img.enemy);
		mlx_destroy_image(engine->mlx_ptr, engine->img.collec);
		mlx_destroy_image(engine->mlx_ptr, engine->img.exit_close);
		mlx_destroy_image(engine->mlx_ptr, engine->img.exit_open);
		mlx_destroy_image(engine->mlx_ptr, engine->img.p0);
		mlx_destroy_image(engine->mlx_ptr, engine->img.p1);
		err_xpm(engine, "bad (player frame 3) xpm file!");
	}
	else if (!engine->img.p3)
	{
		mlx_destroy_image(engine->mlx_ptr, engine->img.wall);
		mlx_destroy_image(engine->mlx_ptr, engine->img.floor);
		mlx_destroy_image(engine->mlx_ptr, engine->img.enemy);
		mlx_destroy_image(engine->mlx_ptr, engine->img.collec);
		mlx_destroy_image(engine->mlx_ptr, engine->img.exit_close);
		mlx_destroy_image(engine->mlx_ptr, engine->img.exit_open);
		mlx_destroy_image(engine->mlx_ptr, engine->img.p0);
		mlx_destroy_image(engine->mlx_ptr, engine->img.p1);
		mlx_destroy_image(engine->mlx_ptr, engine->img.p2);
	}
	check_xpm_part4(engine);
}

static void	check_xpm_part2(t_game *engine)
{
	if (!engine->img.p0)
	{
		mlx_destroy_image(engine->mlx_ptr, engine->img.wall);
		mlx_destroy_image(engine->mlx_ptr, engine->img.floor);
		mlx_destroy_image(engine->mlx_ptr, engine->img.enemy);
		mlx_destroy_image(engine->mlx_ptr, engine->img.collec);
		mlx_destroy_image(engine->mlx_ptr, engine->img.exit_close);
		mlx_destroy_image(engine->mlx_ptr, engine->img.exit_open);
		err_xpm(engine, "bad (player frame 1) xpm file!");
	}
	else if (!engine->img.p1)
	{
		mlx_destroy_image(engine->mlx_ptr, engine->img.wall);
		mlx_destroy_image(engine->mlx_ptr, engine->img.floor);
		mlx_destroy_image(engine->mlx_ptr, engine->img.enemy);
		mlx_destroy_image(engine->mlx_ptr, engine->img.collec);
		mlx_destroy_image(engine->mlx_ptr, engine->img.exit_close);
		mlx_destroy_image(engine->mlx_ptr, engine->img.exit_open);
		mlx_destroy_image(engine->mlx_ptr, engine->img.p0);
		err_xpm(engine, "bad (player frame 2) xpm file!");
	}
	else
		check_xpm_part3(engine);
}

static void	check_xpm_part1(t_game *engine)
{
	if (!engine->img.exit_close)
	{
		mlx_destroy_image(engine->mlx_ptr, engine->img.wall);
		mlx_destroy_image(engine->mlx_ptr, engine->img.floor);
		mlx_destroy_image(engine->mlx_ptr, engine->img.enemy);
		mlx_destroy_image(engine->mlx_ptr, engine->img.collec);
		err_xpm(engine, "bad (closed_exit) xpm file!");
	}
	else if (!engine->img.exit_open)
	{
		mlx_destroy_image(engine->mlx_ptr, engine->img.wall);
		mlx_destroy_image(engine->mlx_ptr, engine->img.floor);
		mlx_destroy_image(engine->mlx_ptr, engine->img.enemy);
		mlx_destroy_image(engine->mlx_ptr, engine->img.collec);
		mlx_destroy_image(engine->mlx_ptr, engine->img.exit_close);
		err_xpm(engine, "bad (opened_exit) xpm file!");
	}
	else
		check_xpm_part2(engine);
}

void	check_xpm(t_game *engine)
{
	if (!engine->img.wall)
		err_xpm(engine, "bad wall xpm file!");
	else if (!engine->img.floor)
	{
		mlx_destroy_image(engine->mlx_ptr, engine->img.wall);
		err_xpm(engine, "bad floor xpm file!");
	}
	else if (!engine->img.enemy)
	{
		mlx_destroy_image(engine->mlx_ptr, engine->img.floor);
		mlx_destroy_image(engine->mlx_ptr, engine->img.wall);
		err_xpm(engine, "bad floor xpm file!");
	}
	else if (!engine->img.collec)
	{
		mlx_destroy_image(engine->mlx_ptr, engine->img.wall);
		mlx_destroy_image(engine->mlx_ptr, engine->img.floor);
		mlx_destroy_image(engine->mlx_ptr, engine->img.enemy);
		err_xpm(engine, "bad collectable xpm file!");
	}
	else
		check_xpm_part1(engine);
}
