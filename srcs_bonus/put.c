/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:33:46 by alebross          #+#    #+#             */
/*   Updated: 2020/06/11 11:53:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

void	putnbr(int n)
{
	int	x;

	x = 1;
	if (n == -2147483648)
	{
		putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		putchar('-');
		n *= -1;
	}
	while (n / x > 9)
		x *= 10;
	while (x)
	{
		ft_putchar((n / x) + 48);
		n %= x;
		x /= 10;
	}
}

void	putendl(char *s)
{
	putstr(s);
	ft_putchar('\n');
}

void	putnbrdl(int n)
{
	putnbr(n);
	ft_putchar('\n');
}
