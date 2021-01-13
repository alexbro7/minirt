/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersec_sq.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:18:33 by alebross          #+#    #+#             */
/*   Updated: 2020/06/11 11:47:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_ray	intersec_sq(t_ray r, t_obj o)
{
	t_square	sq;

	sq = o.sq;
	r.d0 = prdscal(subvec(sq.o, r.o), sq.d.z);
	r.d0 /= prdscal(r.d, sq.d.z);
	if (r.d0 <= 0)
		return (r);
	r.o1 = addvec(r.o, prdvecd(r.d, r.d0));
	if (prdscal(prdvecto(subvec(r.o1, sq.pt[0])
	, sq.vec[0]), sq.d.z) <= 0
	|| prdscal(prdvecto(subvec(r.o1, sq.pt[1])
	, sq.vec[1]), sq.d.z) <= 0
	|| prdscal(prdvecto(subvec(r.o1, sq.pt[2])
	, sq.vec[2]), sq.d.z) <= 0
	|| prdscal(prdvecto(subvec(r.o1, sq.pt[3])
	, sq.vec[3]), sq.d.z) <= 0)
		return (r);
	r.type = 6;
	r.intersection = 1;
	if (prdscal(r.d, sq.d.z) > 0)
		r.n = prdvecd(sq.d.z, -1);
	else
		r.n = sq.d.z;
	r.c = sq.c;
	return (r);
}
