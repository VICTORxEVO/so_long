/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:28:39 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/03/10 16:34:01 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

size_t	ft_nstrlen(const char *str)
{
	size_t	x;

	x = 0;
	while (str[x] && str[x] != '\n')
		x++;
	return (x);
}