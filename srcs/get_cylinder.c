/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:11:45 by alebross          #+#    #+#             */
/*   Updated: 2020/06/11 11:42:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_obj	get_cylinder(char *s)
{
	unsigned int	i;
	t_obj			obj;
	t_d_vector		rot;

	i = 3;
	obj.cy.o = get_position(s, &i);
	rot = get_orientation(s, &i);
	obj.cy.d.z.x = 0;
	obj.cy.d.z.y = 0;
	obj.cy.d.z.z = 1;
	obj.cy.d = vec_to_vecvec(obj.cy.d.z);
	obj.cy.d = rotation(obj.cy.d, rot.x * 180, 1);
	obj.cy.d = rotation(obj.cy.d, rot.y * 180, 0);
	obj.cy.d = rotation(obj.cy.d, rot.z * 180, 2);
	obj.cy.r = atod(s, &i) * 0.5;
	obj.cy.h = atod(s, &i) * 0.5;
	obj.cy.c = get_colors(s, &i);
	return (calcul_cylinder(obj));
}
