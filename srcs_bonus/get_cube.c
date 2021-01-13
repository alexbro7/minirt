/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cube.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:13:26 by alebross          #+#    #+#             */
/*   Updated: 2020/06/12 20:56:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_obj	get_cube(char *s)
{
	unsigned int	i;
	t_d_vector		rot;
	t_obj			obj;

	i = 3;
	obj.cu.o = get_position(s, &i);
	rot = get_orientation(s, &i);
	obj.cu.d.z.x = 0;
	obj.cu.d.z.y = 0;
	obj.cu.d.z.z = 1;
	obj.cu.d = vec_to_vecvec(obj.cu.d.z);
	obj.cu.d = rotation(obj.cu.d, rot.x * 180, 1);
	obj.cu.d = rotation(obj.cu.d, rot.y * 180, 0);
	obj.cu.d = rotation(obj.cu.d, rot.z * 180, 2);
	obj.cu.h = atod(s, &i) * 0.5;
	obj.cu.c = get_colors(s, &i);
	obj = calcul_cube(obj);
	return (obj);
}
