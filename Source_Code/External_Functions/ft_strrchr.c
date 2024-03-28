/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 11:55:37 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/03/04 13:20:01 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

char	*ft_strrchr(const char *str, int c)
{
	int	b;

	b = ft_strlen(str);
	while (b >= 0)
	{
		if (str[b] == (unsigned char)c)
			return ((char *)&str[b]);
		b--;
	}
	return (NULL);
}
