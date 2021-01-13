/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersec_cu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:19:01 by alebross          #+#    #+#             */
/*   Updated: 2020/06/23 18:27:21 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_ray	intersec_cu(t_ray r, t_obj o)
{
	t_ray	tmp;
	t_ray	ret;
	int		i;
	t_obj	t;

	i = 0;
	ret = r;
	while (i < 6)
	{
		t.sq = o.cu.sq[i];
		tmp = intersec_sq(r, t);
		if (tmp.intersection && tmp.d0 >= 0 && (tmp.d0 < ret.d0
			|| !ret.intersection))
			ret = tmp;
		i++;
	}
	if (ret.intersection)
		ret.type = 10;
	return (ret);
}
