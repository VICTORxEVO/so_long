/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:12:53 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/03/23 17:40:27 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	check_arg(int ac, char *path)
{
	if (ac != 2)
	{
		if (ac < 2)
		{
			ft_printf("so_long:%s too few arguments!%s\n", RED, END);
		}
		else
			ft_printf("so_long:%s too many arguments!%s\n", RED, END);
		exit(EXIT_FAILURE);
	}
	path = ft_strrchr(path, '.');
	if (!path)
	{
		ft_printf("so_long:%s invalid map path%s\n", RED, END);
		exit(EXIT_FAILURE);
	}
	if (ft_strcmp(path, ".ber"))
	{
		check_file_ext(path);
	}
}

void	check_file_ext(void *path)
{
	ft_printf("so_long:%s wrong file extension: %s\'%s\'\n", RED, END, path);
	exit(EXIT_FAILURE);
}
