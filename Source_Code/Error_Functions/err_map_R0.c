/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_map_R0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:16:50 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/03/21 15:17:11 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	err_player(t_game *engine, int player, char *str)
{
	ft_printf("so_long: %s%s %d players%s\n", RED, str, player, END);
	shutdown_game(engine);
}

void	err_collec(t_game *engine)
{
	ft_printf("so_long: %syou must have at least 1 collectable%s\n", RED, END);
	shutdown_game(engine);
}

void	err_exit(t_game *engine, int e, char *str)
{
	ft_printf("so_long: %s%s %d%s\n", RED, str, e, END);
	shutdown_game(engine);
}

void	err_wall(t_game *engine)
{
	ft_printf("so_long: %sMap isn't surounded by walls%s\n", RED, END);
	shutdown_game(engine);
}

void	err_rectangle(t_game *engine)
{
	ft_printf("so_long: %sMap isn't rectangular. Please fix it%s\n", RED, END);
	shutdown_game(engine);
}
