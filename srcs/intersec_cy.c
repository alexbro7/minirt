/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersec_cy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:19:01 by alebross          #+#    #+#             */
/*   Updated: 2020/06/11 11:46:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_ray	intersec_cy1(t_ray r, t_cylinder c, double h)
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

t_ray	intersec_cy(t_ray r, t_obj o)
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
	return (intersec_cy1(r, c, 0));
}
