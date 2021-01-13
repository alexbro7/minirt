/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:14:28 by alebross          #+#    #+#             */
/*   Updated: 2020/06/23 19:01:50 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static t_color	color_filtre(t_color c, int filtre)
{
	t_d_vector	d;

	d = clr_to_d(c);
	if (filtre == 1)
	{
		d.x = 0.393 * d.x + 0.769 * d.y + 0.189 * d.z;
		d.y = 0.249 * d.x + 0.686 * d.y + 0.168 * d.z;
		d.z = 0.272 * d.x + 0.534 * d.y + 0.131 * d.z;
	}
	else if (filtre == 2)
	{
		d.y = 0;
		d.z = 0;
	}
	else if (filtre == 3)
	{
		d.x = 0;
	}
	return (d_to_clr(d));
}

t_ray			init_ray(int x, int y, t_display d)
{
	t_ray		ray;
	t_d_vector	v;

	ray.c.r = 0;
	ray.c.g = 0;
	ray.c.b = 0;
	ray.o = d.c.o;
	ray.d.x = (2 * ((x + 0.5) / d.r.x) - 1.0) * ((double)d.r.x / (double)d.r.y);
	ray.d.y = 1 - 2 * ((y + 0.5) / d.r.y);
	ray.d.x *= tan(((double)d.c.fov / 2) * 0.017453292519943295);
	ray.d.y *= tan(((double)d.c.fov / 2) * 0.017453292519943295);
	ray.d.z = -1;
	v = addvec(d.c.d.z, prdvecd(d.c.d.x, ray.d.x));
	v = addvec(v, prdvecd(d.c.d.y, ray.d.y));
	ray.d = normalize(v);
	ray.intersection = 0;
	ray.d0 = 0;
	ray.type = 0;
	ray.id = 0;
	ray = intersec(ray, d.lst);
	if (ray.intersection && ray.type > 3)
		ray.c = rapport_shad(ray, lst_a(d.lst), d.lst);
	if (d.c.filtre)
		ray.c = color_filtre(ray.c, d.c.filtre);
	return (ray);
}
