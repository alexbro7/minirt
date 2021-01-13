/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atod.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 17:45:57 by alebross          #+#    #+#             */
/*   Updated: 2020/06/11 11:31:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

double		atod2(const char *s, unsigned int *i)
{
	int			a;
	double		nb;

	a = *i;
	nb = 0;
	while (s[*i] >= '0' && s[*i] <= '9')
	{
		nb *= 10;
		nb += s[*i] - '0';
		*i += 1;
	}
	a = *i - a;
	while (a)
	{
		nb /= 10;
		a--;
	}
	return (nb);
}

double		atod(const char *s, unsigned int *i)
{
	int			sign;
	double		nb;

	nb = 0;
	while (s[*i] == '\t' || s[*i] == ' ')
		*i += 1;
	sign = (s[*i] == '-' ? -1 : 1);
	*i += (s[*i] == '-' ? 1 : 0);
	while (s[*i] >= '0' && s[*i] <= '9')
	{
		nb *= 10;
		nb += s[*i] - '0';
		*i += 1;
	}
	if (s[*i] == '.')
	{
		*i += 1;
		nb += atod2(s, i);
	}
	return (nb * sign);
}
