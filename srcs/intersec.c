/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:18:08 by alebross          #+#    #+#             */
/*   Updated: 2020/06/22 18:57:15 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_ray	intersec2(t_ray r, t_list *lst, t_ray (**ptr)(t_ray, t_obj))
{
	t_ray	tmp;
	t_ray	ret;

	ret = r;
	while (lst)
	{
		if (lst->type > 2 && lst->type < 9)
		{
			tmp = ptr[lst->type - 3](r, lst->ctt);
			if (tmp.intersection && tmp.d0 >= 0
				&& (tmp.d0 < ret.d0 || !ret.intersection))
			{
				ret = tmp;
				ret.id = lst->id;
			}
		}
		lst = lst->next;
	}
	return (ret);
}

t_ray	intersec(t_ray r, t_list *lst)
{
	t_ray	(*ptr[6])(t_ray r, t_obj o);

	ptr[0] = &intersec_l;
	ptr[1] = &intersec_sp;
	ptr[2] = &intersec_pl;
	ptr[3] = &intersec_sq;
	ptr[4] = &intersec_cy;
	ptr[5] = &intersec_tr;
	return (intersec2(r, lst, ptr));
}
