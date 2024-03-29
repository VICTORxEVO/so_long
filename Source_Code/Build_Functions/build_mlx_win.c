/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_mlx_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:12:21 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/03/29 22:43:06 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	win_close(t_game *engine)
{
	shutdown_game_win(engine, "WINDOW CLOSED!!");
	return (0);
}

static void	*fetch_img(void *mlx, char *path, int *size, t_game *engine)
{
	void	*ptr;

	ptr = mlx_xpm_file_to_image(mlx, path, size, size);
	if (!ptr)
		check_xpm(engine);
	return (ptr);
}

static void	get_img_ptr(t_game *engine, char c, char *path, int *size)
{
	if (c == WALL)
		engine->img.wall = fetch_img(engine->mlx_ptr, path, size, engine);
	else if (c == FLOOR)
		engine->img.floor = fetch_img(engine->mlx_ptr, path, size, engine);
	else if (c == ENEMY)
		engine->img.enemy = fetch_img(engine->mlx_ptr, path, size, engine);
	else if (c == COLLEC)
		engine->img.collec = fetch_img(engine->mlx_ptr, path, size, engine);
	else if (c == 'n')
		engine->img.exit_close = fetch_img(engine->mlx_ptr, path, size, engine);
	else if (c == 'y')
		engine->img.exit_open = fetch_img(engine->mlx_ptr, path, size, engine);
	else if (c == 'a')
		engine->img.p0 = fetch_img(engine->mlx_ptr, path, size, engine);
	else if (c == 'b')
		engine->img.p1 = fetch_img(engine->mlx_ptr, path, size, engine);
	else if (c == 'c')
		engine->img.p2 = fetch_img(engine->mlx_ptr, path, size, engine);
	else if (c == 'd')
		engine->img.p3 = fetch_img(engine->mlx_ptr, path, size, engine);
	else if (c == 'e')
		engine->img.p4 = fetch_img(engine->mlx_ptr, path, size, engine);
}

static void	get_started(t_game *engine)
{
	int	size;

	size = CONST;
	get_img_ptr(engine, WALL, "spirites/wall.xpm", &size);
	get_img_ptr(engine, FLOOR, "spirites/floor.xpm", &size);
	get_img_ptr(engine, ENEMY, "spirites/trap.xpm", &size);
	get_img_ptr(engine, COLLEC, "spirites/collectable.xpm", &size);
	get_img_ptr(engine, 'n', "spirites/exit_close.xpm", &size);
	get_img_ptr(engine, 'y', "spirites/exit_open.xpm", &size);
	get_img_ptr(engine, 'a', "spirites/player0.xpm", &size);
	get_img_ptr(engine, 'b', "spirites/player1.xpm", &size);
	get_img_ptr(engine, 'c', "spirites/player2.xpm", &size);
	get_img_ptr(engine, 'd', "spirites/player3.xpm", &size);
	get_img_ptr(engine, 'e', "spirites/player4.xpm", &size);
	engine->player.mv_count = 0;
	engine->player.animation = 0;
}

void	build_mlx_win(t_game *engine)
{
	engine->mlx_ptr = mlx_init();
	if (!engine->mlx_ptr)
	{
		ft_printf("so_long: %sError while initializing the window%s\n", RED,
			END);
		shutdown_game(engine);
	}
	get_started(engine);
	check_xpm(engine);
	engine->win_ptr = mlx_new_window(engine->mlx_ptr, engine->map.col * CONST,
			engine->map.row * CONST, "so_long");
	if (!engine->win_ptr)
	{
		ft_printf("so_long: %sError while initializing the window%s\n", RED,
			END);
		shutdown_game(engine);
	}
	mlx_hook(engine->win_ptr, CLOSE_WIN, 0, win_close, engine);
}
