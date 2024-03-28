/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:59:17 by ysbai-jo          #+#    #+#             */
/*   Updated: 2023/12/12 09:59:23 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
void	ft_putchar(char c, int *len);
void	ft_putstr(const char *s, int *len);
void	ft_putnbr(int n, int *len);
void	ft_putnbrv2(unsigned int n, int *len);
void	ft_putnbr_hec(unsigned int nb, char type, int *len);
void	ft_putadrr(void *f, int *len);

#endif
