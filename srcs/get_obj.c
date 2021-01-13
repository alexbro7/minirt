/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:12:43 by alebross          #+#    #+#             */
/*   Updated: 2020/06/11 11:43:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_d_vector	get_orientation(char *s, unsigned int *i)
{
	t_d_vector	vector;

	vector.x = atod(s, i);
	*i += 1;
	vector.y = atod(s, i);
	*i += 1;
	vector.z = atod(s, i);
	if (vector.x < -1 || vector.x > 1)
		vector.x = (vector.x < 0 ? -1 : 1);
	if (vector.y < -1 || vector.y > 1)
		vector.y = (vector.y < 0 ? -1 : 1);
	if (vector.z < -1 || vector.z > 1)
		vector.z = (vector.z < 0 ? -1 : 1);
	return (vector);
}

t_d_vector	get_position(char *s, unsigned int *i)
{
	t_d_vector	vector;

	vector.x = atod(s, i);
	*i += 1;
	vector.y = atod(s, i);
	*i += 1;
	vector.z = atod(s, i);
	return (vector);
}

t_color		get_colors(char *s, unsigned int *i)
{
	t_color		c;
	int			tmp;

	tmp = ft_atoi(s, i);
	if (tmp < 0 || tmp > 255)
		tmp = (tmp < 0 ? 0 : 255);
	c.r = (unsigned char)tmp;
	*i += 1;
	tmp = ft_atoi(s, i);
	if (tmp < 0 || tmp > 255)
		tmp = (tmp < 0 ? 0 : 255);
	c.g = (unsigned char)tmp;
	*i += 1;
	tmp = ft_atoi(s, i);
	if (tmp < 0 || tmp > 255)
		tmp = (tmp < 0 ? 0 : 255);
	c.b = (unsigned char)tmp;
	return (c);
}

t_obj		get_obj(char *s, int type)
{
	t_obj		(*ptr[9])(char *s);

	ptr[0] = &get_resolution;
	ptr[1] = &get_ambiantlight;
	ptr[2] = &get_camera;
	ptr[3] = &get_light;
	ptr[4] = &get_sphere;
	ptr[5] = &get_plan;
	ptr[6] = &get_square;
	ptr[7] = &get_cylinder;
	ptr[8] = &get_triangle;
	return (ptr[type](s));
}
