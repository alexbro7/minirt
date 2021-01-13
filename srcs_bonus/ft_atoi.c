/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:10:52 by alebross          #+#    #+#             */
/*   Updated: 2020/06/11 11:41:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int		ft_atoi(char const *str, unsigned int *i)
{
	int		sign;
	int		nb;

	sign = 1;
	nb = 0;
	while (str[*i] == '\t' || str[*i] == ' ')
		*i += 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -1;
		*i += 1;
	}
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		nb = 10 * nb + (str[*i] - 48);
		*i += 1;
	}
	return (nb * sign);
}
