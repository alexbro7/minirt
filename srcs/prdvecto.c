/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prdvecto.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:33:38 by alebross          #+#    #+#             */
/*   Updated: 2020/06/11 11:53:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_d_vector	prdvecto(t_d_vector a, t_d_vector b)
{
	t_d_vector	c;

	c.x = a.y * b.z - a.z * b.y;
	c.y = a.z * b.x - a.x * b.z;
	c.z = a.x * b.y - a.y * b.x;
	return (c);
}
