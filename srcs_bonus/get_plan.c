/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:12:53 by alebross          #+#    #+#             */
/*   Updated: 2020/06/11 11:44:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_obj	get_plan(char *s)
{
	unsigned int	i;
	t_obj			obj;
	t_d_vector		rot;

	i = 3;
	obj.pl.o = get_position(s, &i);
	rot = get_orientation(s, &i);
	obj.pl.d.z.x = 0;
	obj.pl.d.z.y = 0;
	obj.pl.d.z.z = 1;
	obj.pl.d = vec_to_vecvec(obj.pl.d.z);
	obj.pl.d = rotation(obj.pl.d, rot.x * 180, 1);
	obj.pl.d = rotation(obj.pl.d, rot.y * 180, 0);
	obj.pl.d = rotation(obj.pl.d, rot.z * 180, 2);
	obj.pl.c = get_colors(s, &i);
	return (obj);
}
