/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersec_py.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:19:01 by alebross          #+#    #+#             */
/*   Updated: 2020/06/23 18:31:42 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_ray	intersec_py(t_ray r, t_obj o)
{
	t_ray	tmp;
	t_ray	ret;
	int		i;
	t_obj	t;

	i = 0;
	ret = r;
	t.sq = o.py.sq;
	ret = intersec_sq(r, t);
	while (i < 4)
	{
		t.tr = o.py.tr[i];
		tmp = intersec_tr(r, t);
		if (tmp.intersection && tmp.d0 >= 0 && (tmp.d0 < ret.d0
			|| !ret.intersection))
			ret = tmp;
		i++;
	}
	if (ret.intersection)
		ret.type = 9;
	return (ret);
}
