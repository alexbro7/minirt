/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersec_l.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:25:23 by alebross          #+#    #+#             */
/*   Updated: 2020/06/11 11:46:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_ray	intersec_l(t_ray r, t_obj o)
{
	t_light		li;
	t_geotools	t;

	li = o.l;
	t.l = subvec(li.o, r.o);
	t.ll = norm_eucli(t.l);
	t.tca = prdscal(t.l, r.d);
	if (t.tca < 0)
		return (r);
	t.d = sqrt(t.ll * t.ll - t.tca * t.tca);
	if (t.d < 0 || t.d > li.r)
		return (r);
	r.type = 3;
	r.intersection = 1;
	r.c = li.c;
	t.thc = sqrt(li.r * li.r - t.d * t.d);
	r.d0 = t.tca - t.thc;
	r.d1 = t.tca + t.thc;
	return (r);
}
