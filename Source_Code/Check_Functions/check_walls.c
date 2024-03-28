/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:16:14 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/03/21 15:16:28 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	check_walls(t_game *engine)
{
	int	row;
	int	col;

	row = -1;
	while (engine->map.map[++row])
	{
		col = 0;
		while (engine->map.map[row][col])
		{
			if (row == 0 || row == engine->map.row - 1)
				if (engine->map.map[row][col] != WALL)
					err_wall(engine);
			if (col == 0 || col == engine->map.col - 1)
				if (engine->map.map[row][col] != WALL)
					err_wall(engine);
			col++;
		}
	}
}
