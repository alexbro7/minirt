/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_alia_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 18:25:38 by alebross          #+#    #+#             */
/*   Updated: 2020/06/23 18:26:13 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static t_ray		init_alia_ray2(t_d_vector c, int a, t_ray r)
{
	c = prdvecd(c, 1.0 / (a * a));
	r.c.r = (char)c.x;
	r.c.g = (char)c.y;
	r.c.b = (char)c.z;
	return (r);
}

static t_d_vector	gratte_ligne(t_d_vector c, t_color c1)
{
	c.x += (double)c1.r;
	c.y += (double)c1.g;
	c.z += (double)c1.b;
	return (c);
}

t_ray				init_alia_ray(int x, int y, t_display d)
{
	t_resolution	i[2];
	t_ray			r;
	t_d_vector		c;

	i[0].y = y * d.c.a;
	i[1].x = (x + 1) * d.c.a;
	i[1].y = i[0].y + d.c.a;
	d.r.x *= d.c.a;
	d.r.y *= d.c.a;
	c.x = 0;
	c.y = 0;
	c.z = 0;
	while (i[0].y < i[1].y)
	{
		i[0].x = x * d.c.a;
		while (i[0].x < i[1].x)
		{
			r = init_ray(i[0].x, i[0].y, d);
			c = gratte_ligne(c, r.c);
			i[0].x++;
		}
		i[0].y++;
	}
	return (init_alia_ray2(c, d.c.a, r));
}
