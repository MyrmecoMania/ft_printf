/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enorie <enorie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:40:02 by enorie            #+#    #+#             */
/*   Updated: 2023/11/13 15:44:36 by enorie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *t)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", t);
		return ;
	}
	if (n >= 0 && n <= 9)
		ft_putchar(n + '0', t);
	else if (n < 0)
	{
		ft_putchar('-', t);
		ft_putnbr(n * -1, t);
	}
	else
	{
		ft_putnbr(n / 10, t);
		ft_putnbr(n % 10, t);
	}
}

void	ft_putnbr_u(unsigned int n, int *t)
{
	if (n >= 0 && n <= 9)
		ft_putchar(n + '0', t);
	else
	{
		ft_putnbr(n / 10, t);
		ft_putnbr(n % 10, t);
	}
}

void	ft_putnbr_base(unsigned long long n, char *b, int *t)
{
	if (n >= 0 && n <= 15)
		ft_putchar(b[n], t);
	else
	{
		ft_putnbr_base(n / 16, b, t);
		ft_putnbr_base(n % 16, b, t);
	}
}
