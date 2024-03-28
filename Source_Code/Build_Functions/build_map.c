/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:10:44 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/03/25 21:15:11 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	get_map_rows(t_game *engine)
{
	char	*line;

	engine->map.row = 0;
	line = get_next_line(engine->map.fd);
	if (!line)
	{
		ft_printf("so_long: %sError empty map%s\n", RED, END);
		exit(EXIT_FAILURE);
	}
	while (line)
	{
		engine->map.row++;
		free(line);
		line = get_next_line(engine->map.fd);
	}
	close(engine->map.fd);
	engine->map.map = malloc(sizeof(char *) * (engine->map.row + 1));
	if (!(engine->map.map))
		err_malloc("Memory allocation failed!");
	engine->map.map[engine->map.row] = NULL;
}

static void	get_map(t_game *engine, char *path)
{
	char	*line;
	int		i;

	engine->map.fd = open(path, O_RDONLY);
	line = get_next_line(engine->map.fd);
	i = 0;
	while (line)
	{
		engine->map.map[i] = line;
		line = get_next_line(engine->map.fd);
		i++;
	}
	close(engine->map.fd);
}

void	build_map(char *path, t_game *engine)
{
	engine->map.fd = open(path, O_RDONLY);
	if (engine->map.fd < 0)
	{
		fd_error(path);
	}
	get_map_rows(engine);
	get_map(engine, path);
	check_rectangle(engine);
	check_characters(engine);
	check_walls(engine);
	check_pce(engine);
	check_path2exit(engine);
	check_path2collec(engine);
}
