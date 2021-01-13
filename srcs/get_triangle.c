/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_triangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:13:37 by alebross          #+#    #+#             */
/*   Updated: 2020/06/11 11:45:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_obj	get_triangle2(t_obj obj)
{
	obj.tr.ptinit[0] = subvec(obj.tr.pt[0], obj.tr.v);
	obj.tr.ptinit[1] = subvec(obj.tr.pt[1], obj.tr.v);
	obj.tr.ptinit[2] = subvec(obj.tr.pt[2], obj.tr.v);
	return (obj);
}

t_obj	get_triangle(char *s)
{
	unsigned int	i;
	t_obj			obj;

	i = 3;
	obj.tr.pt[0] = get_position(s, &i);
	obj.tr.pt[1] = get_position(s, &i);
	obj.tr.pt[2] = get_position(s, &i);
	obj.tr.ptinit[0] = obj.tr.pt[0];
	obj.tr.ptinit[1] = obj.tr.pt[1];
	obj.tr.ptinit[2] = obj.tr.pt[2];
	obj.tr.c = get_colors(s, &i);
	obj = calcul_triangle(obj);
	obj.tr.w.x.x = 1;
	obj.tr.w.x.y = 0;
	obj.tr.w.x.z = 0;
	obj.tr.w.y.x = 0;
	obj.tr.w.y.y = 1;
	obj.tr.w.y.z = 0;
	obj.tr.w.z.x = 0;
	obj.tr.w.z.y = 0;
	obj.tr.w.z.z = 1;
	obj.tr.v.x = (obj.tr.pt[0].x + obj.tr.pt[1].x + obj.tr.pt[2].x) / 3.0;
	obj.tr.v.y = (obj.tr.pt[0].y + obj.tr.pt[1].y + obj.tr.pt[2].y) / 3.0;
	obj.tr.v.z = (obj.tr.pt[0].z + obj.tr.pt[1].z + obj.tr.pt[2].z) / 3.0;
	return (get_triangle2(obj));
}
