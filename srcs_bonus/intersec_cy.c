/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersec_cy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:19:01 by alebross          #+#    #+#             */
/*   Updated: 2020/06/23 19:05:30 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_ray	intersec_disk(t_ray r, t_square di)
{
	r.d0 = prdscal(subvec(di.o, r.o), di.d.z);
	r.d0 /= prdscal(r.d, di.d.z);
	if (r.d0 <= 0)
		return (r);
	r.o1 = addvec(r.o, prdvecd(r.d, r.d0));
	if (norm_eucli(subvec(r.o1, di.o)) > di.h)
		return (r);
	if (prdscal(r.d, di.d.z) > 0)
		r.n = prdvecd(di.d.z, -1);
	else
		r.n = di.d.z;
	r.intersection = 1;
	r.type = 7;
	r.c = di.c;
	return (r);
}

t_ray	intersec_cy2(t_ray r, t_cylinder c, double h)
{
	if (r.d0 > 0)
	{
		r.o1 = addvec(r.o, prdvecd(r.d, r.d0));
		h = prdscal(c.d.z, subvec(r.o1, c.o));
		if (h < c.h && h > -c.h)
		{
			r.n = normalize(subvec(subvec(r.o1, c.o), prdvecd(c.d.z, h)));
			r.intersection = 1;
			return (r);
		}
	}
	if (r.d1 > 0)
	{
		r.d0 = r.d1;
		r.o1 = addvec(r.o, prdvecd(r.d, r.d0));
		h = prdscal(c.d.z, subvec(r.o1, c.o));
		if (h < c.h && h > -c.h)
		{
			r.n = normalize(subvec(prdvecd(c.d.z, h), subvec(r.o1, c.o)));
			r.intersection = 1;
			return (r);
		}
	}
	return (r);
}

t_ray	intersec_cy1(t_ray r, t_obj o)
{
	t_cylinder	c;
	t_d_vector	v[2];
	double		d[6];

	c = o.cy;
	v[0] = subvec(r.o, c.o);
	d[0] = prdscal(subvec(r.o, c.o), c.d.z);
	v[0] = subvec(v[0], prdvecd(c.d.z, d[0]));
	v[1] = subvec(r.d, prdvecd(c.d.z, prdscal(r.d, c.d.z)));
	d[3] = norm_eucli(v[0]);
	d[4] = norm_eucli(v[1]);
	d[0] = d[4] * d[4];
	d[1] = 2 * prdscal(v[0], v[1]);
	d[2] = (d[3] * d[3]) - (c.r * c.r);
	d[5] = (d[1] * d[1]) - (4 * d[0] * d[2]);
	if (d[5] < 0)
		return (r);
	r.type = 7;
	r.c = c.c;
	r.d0 = ((d[1] * -1) - sqrt(d[5])) / (2 * d[0]);
	r.d1 = ((d[1] * -1) + sqrt(d[5])) / (2 * d[0]);
	return (intersec_cy2(r, c, 0));
}

t_ray	intersec_capuchon(t_ray r, t_obj o)
{
	t_obj	t;
	t_ray	tmp;
	t_ray	ret;

	ret = r;
	tmp = intersec_cy1(r, o);
	if (tmp.intersection)
		ret = tmp;
	t.sq.o = addvec(o.cy.o, prdvecd(o.cy.d.z, o.cy.h));
	t.sq.d = o.cy.d;
	t.sq.h = o.cy.r;
	t.sq.c = o.cy.c;
	tmp = intersec_disk(r, t.sq);
	if (tmp.intersection && tmp.d0 >= 0
		&& (tmp.d0 < ret.d0 || !ret.intersection))
		ret = tmp;
	t.sq.o = subvec(o.cy.o, prdvecd(o.cy.d.z, o.cy.h));
	tmp = intersec_disk(r, t.sq);
	if (tmp.intersection && tmp.d0 >= 0
		&& (tmp.d0 < ret.d0 || !ret.intersection))
		ret = tmp;
	return (ret);
}

t_ray	intersec_cy(t_ray r, t_obj o)
{
	if (o.cy.capuchon)
		return (intersec_capuchon(r, o));
	else
		return (intersec_cy1(r, o));
}
