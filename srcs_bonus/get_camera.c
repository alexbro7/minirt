/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:11:36 by alebross          #+#    #+#             */
/*   Updated: 2020/06/23 18:21:16 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static int	get_filtre(char *s, unsigned int i)
{
	while (is_space(s[i]))
		i++;
	i++;
	return (s[i] ? 2 : 1);
}

static int	get_antialiasing(char *s, unsigned int *i)
{
	*i += 2;
	while (is_space(s[*i]))
		*i += 1;
	return (ft_atoi(s, i));
}

t_d_vector	gratteligne(void)
{
	t_d_vector	d;

	d.x = 0;
	d.y = 0;
	d.z = 1;
	return (d);
}

t_obj		get_camera(char *s)
{
	t_d_vector		rot;
	t_obj			obj;
	unsigned int	i;

	i = 2;
	obj.cmr.o = get_position(s, &i);
	rot = get_orientation(s, &i);
	obj.cmr.d.z = gratteligne();
	obj.cmr.d = vec_to_vecvec(obj.cmr.d.z);
	obj.cmr.d = rotation(obj.cmr.d, rot.x * 180, 0);
	obj.cmr.d = rotation(obj.cmr.d, rot.y * 180, 1);
	obj.cmr.d = rotation(obj.cmr.d, rot.z * 180, 2);
	obj.cmr.fov = ft_atoi(s, &i);
	if (obj.cmr.fov < 0 || obj.cmr.fov > 180)
		obj.cmr.fov = (obj.cmr.fov < 0 ? 0 : 180);
	if (is_space(s[i]))
		while (is_space(s[i]))
			i++;
	obj.cmr.a = (s[i] == 'a' ? get_antialiasing(s, &i) : 0);
	if (is_space(s[i]))
		while (is_space(s[i]))
			i++;
	obj.cmr.filtre = (s[i] == 's' ? get_filtre(s, i) : 0);
	return (obj);
}
