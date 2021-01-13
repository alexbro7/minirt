/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_cube.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 17:46:07 by alebross          #+#    #+#             */
/*   Updated: 2020/06/23 18:09:14 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_obj	calcul_cube(t_obj obj)
{
	t_obj	tmp;
	int		i;

	i = 0;
	obj.cu.sq[0].o = subvec(obj.cu.o, prdvecd(obj.cu.d.z, obj.cu.h));
	obj.cu.sq[0].d = obj.cu.d;
	obj.cu.sq[1].o = addvec(obj.cu.o, prdvecd(obj.cu.d.z, obj.cu.h));
	obj.cu.sq[1].d = obj.cu.d;
	obj.cu.sq[2].o = subvec(obj.cu.o, prdvecd(obj.cu.d.x, obj.cu.h));
	obj.cu.sq[2].d = rotation(obj.cu.d, 90, 0);
	obj.cu.sq[3].o = addvec(obj.cu.o, prdvecd(obj.cu.d.x, obj.cu.h));
	obj.cu.sq[3].d = rotation(obj.cu.d, 90, 0);
	obj.cu.sq[4].o = subvec(obj.cu.o, prdvecd(obj.cu.d.y, obj.cu.h));
	obj.cu.sq[4].d = rotation(obj.cu.d, 90, 1);
	obj.cu.sq[5].o = addvec(obj.cu.o, prdvecd(obj.cu.d.y, obj.cu.h));
	obj.cu.sq[5].d = rotation(obj.cu.d, 90, 1);
	while (i < 6)
	{
		obj.cu.sq[i].h = obj.cu.h;
		obj.cu.sq[i].c = obj.cu.c;
		tmp.sq = obj.cu.sq[i];
		obj.cu.sq[i] = calcul_square(tmp).sq;
		i++;
	}
	return (obj);
}
