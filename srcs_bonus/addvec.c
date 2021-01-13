/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addvec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 17:45:42 by alebross          #+#    #+#             */
/*   Updated: 2020/06/11 11:31:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_d_vector	addvec(t_d_vector a, t_d_vector b)
{
	t_d_vector	c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.z = a.z + b.z;
	return (c);
}
