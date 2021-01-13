/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_pyramide.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 17:46:07 by alebross          #+#    #+#             */
/*   Updated: 2020/06/23 18:08:46 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static t_square		get_sq_for_py(t_pyramide py)
{
	t_obj		o;
	t_square	sq;

	o.sq.o = subvec(py.o, prdvecd(py.d.y, py.h));
	o.sq.d = rotation(py.d, 90, 1);
	o.sq.h = py.r;
	o = calcul_square(o);
	o.sq.c = py.c;
	sq = o.sq;
	return (sq);
}

static t_triangle	get_tr_for_py(t_square sq, t_d_vector s, int i)
{
	t_obj	o;
	int		j;

	j = (i == 3 ? 0 : i + 1);
	o.tr.pt[0] = sq.pt[i];
	o.tr.pt[1] = s;
	o.tr.pt[2] = sq.pt[j];
	o.tr.c = sq.c;
	o = calcul_triangle(o);
	return (o.tr);
}

t_obj				calcul_pyramide(t_obj obj)
{
	int		i;

	i = 0;
	obj.py.s = addvec(obj.py.o, prdvecd(obj.py.d.y, obj.py.h));
	obj.py.sq = get_sq_for_py(obj.py);
	while (i < 4)
	{
		obj.py.tr[i] = get_tr_for_py(obj.py.sq, obj.py.s, i);
		i++;
	}
	return (obj);
}
