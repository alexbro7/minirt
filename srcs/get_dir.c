/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:11:54 by alebross          #+#    #+#             */
/*   Updated: 2020/06/11 11:42:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_d_vector	get_dir(t_d_vector a, t_d_vector b)
{
	t_d_vector	c;
	double		d;

	c = subvec(b, a);
	d = norm_eucli(c);
	c.x /= d;
	c.y /= d;
	c.z /= d;
	return (c);
}
