/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rectangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:15:34 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/03/21 15:15:53 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	check_rectangle(t_game *engine)
{
	int	row;

	row = -1;
	engine->map.col = ft_nstrlen(engine->map.map[0]);
	while (engine->map.map[++row])
	{
		if (ft_nstrlen(engine->map.map[row]) != (size_t)engine->map.col)
			err_rectangle(engine);
	}
	row = -1;
	while (++row < engine->map.row)
		engine->map.map[row][engine->map.col] = 0;
}
