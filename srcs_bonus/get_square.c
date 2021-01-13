/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:13:26 by alebross          #+#    #+#             */
/*   Updated: 2020/07/01 11:25:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_obj	get_square(char *s)
{
	unsigned int	i;
	t_d_vector		rot;
	t_obj			obj;

	i = 3;
	obj.sq.o = get_position(s, &i);
	rot = get_orientation(s, &i);
	obj.sq.d.z.x = 0;
	obj.sq.d.z.y = 0;
	obj.sq.d.z.z = 1;
	obj.sq.d = vec_to_vecvec(obj.sq.d.z);
	obj.sq.d = rotation(obj.sq.d, rot.x * 180, 1);
	obj.sq.d = rotation(obj.sq.d, rot.y * 180, 0);
	obj.sq.d = rotation(obj.sq.d, rot.z * 180, 2);
	obj.sq.h = absolute(atod(s, &i) * 0.5);
	obj.sq.c = get_colors(s, &i);
	obj = calcul_square(obj);
	return (obj);
}
