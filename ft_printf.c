/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enorie <enorie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:32:40 by enorie            #+#    #+#             */
/*   Updated: 2023/11/13 15:45:15 by enorie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_putchar(char a, int *t)
{
	write(1, &a, 1);
	(*t)++;
}

void	ft_putstr(char *s, int *t)
{
	int	i;

	i = 0;
	if (!s)
		s = "(null)";
	while (s[i])
		ft_putchar(s[i++], t);
}

void	ft_checkp(unsigned long long i, int *t)
{
	if (!i)
		ft_putstr("(nil)", t);
	else
	{
		ft_putstr("0x", t);
		ft_putnbr_base(i, "0123456789abcdef", t);
	}
}

int	ft_choose(char c, va_list params, int *t)
{
	unsigned long long	i;

	i = 0;
	if (c == 'c')
		ft_putchar(va_arg(params, int), t);
	else if (c == 's')
		ft_putstr(va_arg(params, char *), t);
	else if (c == 'p')
	{
		i = va_arg(params, unsigned long long);
		ft_checkp(i, t);
	}	
	else if (c == 'i' || c == 'd')
		ft_putnbr(va_arg(params, int), t);
	else if (c == 'u')
		ft_putnbr_u(va_arg(params, int), t);
	else if (c == 'x')
		ft_putnbr_base(va_arg(params, unsigned int), "0123456789abcdef", t);
	else if (c == 'X')
		ft_putnbr_base(va_arg(params, unsigned int), "0123456789ABCDEF", t);
	else if (c == '%')
		ft_putchar('%', t);
	else
		return (0);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		t;
	int		*tp;
	va_list	params;

	va_start(params, str);
	tp = &t;
	i = 0;
	t = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (!ft_choose(str[i + 1], params, tp))
				ft_putchar(str[i], tp);
			i++;
		}
		else
			ft_putchar(str[i], tp);
		i++;
	}
	va_end(params);
	return (t);
}
