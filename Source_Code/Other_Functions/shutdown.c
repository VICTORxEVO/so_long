/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shutdown.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:18:57 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/03/25 22:03:48 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	shutdown_game_success(t_game *engine)
{
	mlx_destroy_image(engine->mlx_ptr, engine->img.wall);
	mlx_destroy_image(engine->mlx_ptr, engine->img.floor);
	mlx_destroy_image(engine->mlx_ptr, engine->img.collec);
	mlx_destroy_image(engine->mlx_ptr, engine->img.exit_open);
	mlx_destroy_image(engine->mlx_ptr, engine->img.exit_close);
	mlx_destroy_image(engine->mlx_ptr, engine->img.p0);
	mlx_destroy_image(engine->mlx_ptr, engine->img.p1);
	mlx_destroy_image(engine->mlx_ptr, engine->img.p2);
	mlx_destroy_image(engine->mlx_ptr, engine->img.p3);
	mlx_destroy_image(engine->mlx_ptr, engine->img.p4);
	mlx_destroy_image(engine->mlx_ptr, engine->img.enemy);
	mlx_destroy_window(engine->mlx_ptr, engine->win_ptr);
	mlx_destroy_display(engine->mlx_ptr);
	free(engine->mlx_ptr);
	exit(EXIT_SUCCESS);
}

void	shutdown_game(t_game *engine)
{
	int	i;

	i = -1;
	while (engine->map.map[++i])
		free(engine->map.map[i]);
	free(engine->map.map);
	exit(EXIT_FAILURE);
}

void	shutdown_game_win(t_game *engine, char *str)
{
	int	i;

	i = -1;
	usleep(200000);
	ft_printf("%s", CLEAR);
	if (!ft_strcmp(str, "YOU WIN"))
	{
		ft_printf("%sCONGRATULATION !!\n>!>!>!>!>!YOU WON!<!<!<!<!<\n%s",
			BOLDYELLOW, END);
	}
	else
		ft_printf("%s%s%s\n", BOLDRED, str, END);
	while (engine->map.map[++i])
		free(engine->map.map[i]);
	free(engine->map.map);
	shutdown_game_success(engine);
}

void	free_vmap(t_game *engine)
{
	int	i;

	i = -1;
	while (engine->map.vmap[++i])
		free(engine->map.vmap[i]);
	free(engine->map.vmap);
	free(engine->stack);
}
