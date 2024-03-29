/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_map_R2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:16:58 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/03/29 17:20:10 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	err_malloc(char *str)
{
	ft_printf("Malloc: %s%s%s\n", RED, str, END);
	exit(EXIT_FAILURE);
}

void	err_malloc_v2(char *str, t_game *engine)
{
	ft_printf("Malloc: %s%s%s\n", RED, str, END);
	shutdown_game(engine);
}

void	fd_error(char *path)
{
	ft_printf("so_long: %sno such a file or directory:%s %s\n", RED, END, path);
	exit(EXIT_FAILURE);
}

void	err_xpm(t_game *engine, char *msg)
{
	ft_printf("so_long: %s%s%s\n", RED, msg, END);
	mlx_destroy_display(engine->mlx_ptr);
	free(engine->mlx_ptr);
	shutdown_game(engine);
}
