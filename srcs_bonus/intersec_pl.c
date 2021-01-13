/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersec_pl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:18:44 by alebross          #+#    #+#             */
/*   Updated: 2020/06/11 11:46:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_ray	intersec_pl(t_ray r, t_obj o)
{
	t_plane		pl;

	pl = o.pl;
	r.d0 = prdscal(subvec(pl.o, r.o), pl.d.z);
	r.d0 /= prdscal(r.d, pl.d.z);
	if (r.d0 <= 0)
		return (r);
	r.type = 5;
	if (prdscal(r.d, pl.d.z) > 0)
		r.n = prdvecd(pl.d.z, -1);
	else
		r.n = pl.d.z;
	r.intersection = 1;
	r.o1 = addvec(r.o, prdvecd(r.d, r.d0));
	r.c = pl.c;
	return (r);
}
