/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enorie <enorie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:44:17 by enorie            #+#    #+#             */
/*   Updated: 2023/11/13 15:44:56 by enorie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

void	ft_putnbr(int n, int *t);
void	ft_putnbr_u(unsigned int n, int *t);
void	ft_putnbr_base(unsigned long long n, char *b, int *t);
void	ft_putchar(char a, int *t);
void	ft_putstr(char *s, int *t);
int		ft_choose(char c, va_list params, int *t);
int		ft_printf(const char *str, ...);

#endif