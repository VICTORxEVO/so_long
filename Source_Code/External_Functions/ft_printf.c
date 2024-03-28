/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:34:32 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/03/04 13:14:23 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	check_frmt(const char c, va_list arg, int *len)
{
	if (c == 'i' || c == 'd')
		ft_putnbr(va_arg(arg, int), len);
	else if (c == 'u')
		ft_putnbrv2(va_arg(arg, unsigned int), len);
	else if (c == 'c')
		ft_putchar((char)va_arg(arg, int), len);
	else if (c == 's')
		ft_putstr(va_arg(arg, char *), len);
	else if (c == 'p')
		ft_putadrr(va_arg(arg, void *), len);
	else if (c == 'X')
		ft_putnbr_hec(va_arg(arg, unsigned int), c, len);
	else if (c == 'x')
		ft_putnbr_hec(va_arg(arg, unsigned int), c, len);
	else if (c == '%')
		ft_putchar('%', len);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int		len;

	va_start(arg, s);
	len = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			check_frmt(*s, arg, &len);
		}
		else
			ft_putchar(*s, &len);
		s++;
	}
	va_end(arg);
	return (len);
}
