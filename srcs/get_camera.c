/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:11:36 by alebross          #+#    #+#             */
/*   Updated: 2020/06/18 13:47:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_obj	get_camera(char *s)
{
	t_d_vector		rot;
	t_obj			obj;
	unsigned int	i;

	i = 2;
	obj.cmr.o = get_position(s, &i);
	rot = get_orientation(s, &i);
	obj.cmr.d.z.x = 0;
	obj.cmr.d.z.y = 0;
	obj.cmr.d.z.z = 1;
	obj.cmr.d = vec_to_vecvec(obj.cmr.d.z);
	obj.cmr.d = rotation(obj.cmr.d, rot.x * 180, 0);
	obj.cmr.d = rotation(obj.cmr.d, rot.y * 180, 1);
	obj.cmr.d = rotation(obj.cmr.d, rot.z * 180, 2);
	obj.cmr.fov = ft_atoi(s, &i);
	if (obj.cmr.fov < 0 || obj.cmr.fov > 180)
		obj.cmr.fov = (obj.cmr.fov < 0 ? 0 : 180);
	return (obj);
}
