/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersec_tr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:19:07 by alebross          #+#    #+#             */
/*   Updated: 2020/06/11 11:47:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_ray	intersec_tr(t_ray r, t_obj o)
{
	t_triangle	tr;

	tr = o.tr;
	r.d0 = prdscal(subvec(tr.pt[0], r.o), tr.d);
	r.d0 /= prdscal(r.d, tr.d);
	if (r.d0 <= 0)
		return (r);
	r.o1 = addvec(r.o, prdvecd(r.d, r.d0));
	if (prdscal(prdvecto(subvec(r.o1, tr.pt[0])
	, tr.vec[0]), tr.d) >= 0
	|| prdscal(prdvecto(subvec(r.o1, tr.pt[1])
	, tr.vec[1]), tr.d) >= 0
	|| prdscal(prdvecto(subvec(r.o1, tr.pt[2])
	, tr.vec[2]), tr.d) >= 0)
		return (r);
	r.type = 8;
	r.intersection = 1;
	if (prdscal(r.d, tr.d) > 0)
		r.n = prdvecd(tr.d, -1);
	else
		r.n = tr.d;
	r.c = tr.c;
	return (r);
}
