/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pyramide.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:11:45 by alebross          #+#    #+#             */
/*   Updated: 2020/06/12 01:16:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_obj				get_pyramide(char *s)
{
	unsigned int	i;
	t_obj			obj;
	t_d_vector		rot;

	i = 3;
	obj.py.o = get_position(s, &i);
	rot = get_orientation(s, &i);
	obj.py.d.z.x = 0;
	obj.py.d.z.y = 0;
	obj.py.d.z.z = 1;
	obj.py.d = vec_to_vecvec(obj.cy.d.z);
	obj.py.d = rotation(obj.py.d, rot.x * 180, 1);
	obj.py.d = rotation(obj.py.d, rot.y * 180, 0);
	obj.py.d = rotation(obj.py.d, rot.z * 180, 2);
	obj.py.r = atod(s, &i) * 0.5;
	obj.py.h = atod(s, &i) * 0.5;
	obj.py.c = get_colors(s, &i);
	return (calcul_pyramide(obj));
}
