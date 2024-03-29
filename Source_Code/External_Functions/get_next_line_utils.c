/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:24:36 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/03/29 18:13:05 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

char	*ft_strjoin(char **s1, char const *s2, int rd)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new;

	if (!rd)
		return (*s1);
	if (!*s1)
		return (ft_substr(s2, 0, rd));
	s1_len = ft_strlen(*s1);
	s2_len = ft_strlen(s2);
	new = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!new)
		return (NULL);
	ft_memcpy(new, *s1, s1_len);
	ft_strlcpy(&new[s1_len], s2, s2_len + 1);
	free(*s1);
	return (new);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	b;

	if (!dest && !src)
		return (NULL);
	b = 0;
	while (b < n && dest != src)
	{
		*((t_uc *)(dest + b)) = *((const t_uc *)(src + b));
		++b;
	}
	return (dest);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	x;

	x = 0;
	if (size)
	{
		while (src[x] && x < (size - 1))
		{
			dest[x] = src[x];
			x++;
		}
		dest[x] = 0;
	}
	return (ft_strlen(src));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_l;

	if (!s)
		return (NULL);
	s_l = ft_strlen(s);
	if (start >= s_l)
		return (ft_strdupp(""));
	else if (start + len >= s_l)
	{
		sub = malloc(sizeof(char) * (s_l - start + 1));
		if (!sub)
			return (NULL);
		ft_strlcpy(sub, &s[start], (s_l - start + 1));
	}
	else
	{
		sub = malloc(sizeof(char) * (len + 1));
		if (!sub)
			return (NULL);
		ft_strlcpy(sub, &s[start], (len + 1));
	}
	return (sub);
}

size_t	ft_strlen(const char *str)
{
	size_t	x;

	x = 0;
	while (str[x])
		x++;
	return (x);
}
