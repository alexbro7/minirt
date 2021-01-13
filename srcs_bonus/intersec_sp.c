/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersec_sp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:18:19 by alebross          #+#    #+#             */
/*   Updated: 2020/06/11 11:47:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_ray	intersec_sp1(t_ray r, t_sphere s)
{
	if (r.d0 > 0)
	{
		r.o1 = addvec(r.o, prdvecd(r.d, r.d0));
		r.n = normalize(subvec(r.o1, s.o));
	}
	else if (r.d1 > 0)
	{
		r.o1 = addvec(r.o, prdvecd(r.d, r.d1));
		r.n = normalize(subvec(s.o, r.o1));
		r.d0 = r.d1;
	}
	r.intersection = 1;
	r.type = 4;
	r.c = s.c;
	return (r);
}

t_ray	intersec_sp(t_ray r, t_obj o)
{
	t_sphere	s;
	t_geotools	t;

	s = o.sp;
	t.l = subvec(s.o, r.o);
	t.ll = norm_eucli(t.l);
	t.tca = prdscal(t.l, r.d);
	t.d = sqrt(t.ll * t.ll - t.tca * t.tca);
	if (t.d > s.r)
		return (r);
	t.thc = sqrt(s.r * s.r - t.d * t.d);
	r.d0 = t.tca - t.thc;
	r.d1 = t.tca + t.thc;
	if (r.d0 <= 0 && r.d1 <= 0)
		return (r);
	return (intersec_sp1(r, s));
}
