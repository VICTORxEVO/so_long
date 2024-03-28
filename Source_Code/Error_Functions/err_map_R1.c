/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_map_R1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:16:54 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/03/21 15:16:55 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	err_characters(t_game *engine, char c)
{
	ft_printf("so_long: %sunexpected character found: \'%c\'%s\n", RED, c, END);
	shutdown_game(engine);
}

void	err_path2exit(t_game *engine)
{
	ft_printf("so_long: %sUnwinable map%s. the game is endless%s\n", RED,
		BOLDYELLOW, END);
	free_vmap(engine);
	shutdown_game(engine);
}

void	err_path2collec(t_game *engine, int c, char *str)
{
	printf("so_long: %s%s %d remaining colletables%s\n", RED, str, c, END);
	free_vmap(engine);
	shutdown_game(engine);
}
