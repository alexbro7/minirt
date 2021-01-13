/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raster.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:14:11 by alebross          #+#    #+#             */
/*   Updated: 2020/06/23 18:59:26 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static void		gratteligne(t_display d, t_camera *c1, t_camera *c2)
{
	*c1 = d.c;
	c1->o = subvec(d.c.o, prdvecd(d.c.d.x, 1.3));
	*c2 = d.c;
	c2->o = addvec(d.c.o, prdvecd(d.c.d.x, 1.3));
	c2->filtre = 3;
}

static t_ray	**init_raster2(t_display d)
{
	t_resolution	i;
	t_camera		c[2];

	gratteligne(d, &c[0], &c[1]);
	i.y = 0;
	while (i.y < d.r.y)
	{
		i.x = 0;
		while (i.x < d.r.x)
		{
			d.c = c[0];
			d.raster[i.y][i.x] = (d.c.a > 1 ?
					init_alia_ray(i.x, i.y, d) : init_ray(i.x, i.y, d));
			d.c = c[1];
			if (d.c.a > 1)
				d.raster[i.y][i.x].c =
				addcolor(d.raster[i.y][i.x].c, init_alia_ray(i.x, i.y, d).c);
			else
				d.raster[i.y][i.x].c =
				addcolor(d.raster[i.y][i.x].c, init_ray(i.x, i.y, d).c);
			i.x++;
		}
		i.y++;
	}
	return (d.raster);
}

static t_ray	**init_raster1(t_display d)
{
	t_resolution	i;

	i.y = 0;
	while (i.y < d.r.y)
	{
		i.x = 0;
		while (i.x < d.r.x)
		{
			if (d.c.a > 1)
				d.raster[i.y][i.x] = init_alia_ray(i.x, i.y, d);
			else
				d.raster[i.y][i.x] = init_ray(i.x, i.y, d);
			i.x++;
		}
		i.y++;
	}
	return (d.raster);
}

t_ray			**init_raster(t_display d)
{
	t_resolution	i;

	if (!(d.raster = malloc(sizeof(t_ray *) * d.r.y)))
	{
		error_msg(5, NULL, d.cx - 1, 0);
		return (NULL);
	}
	i.y = 0;
	while (i.y < d.r.y)
	{
		if (!(d.raster[i.y] = malloc(sizeof(t_ray) * d.r.x)))
		{
			free_raster1(d.raster, i.y);
			error_msg(6, NULL, i.y, 0);
			return (NULL);
		}
		i.y++;
	}
	if (d.c.filtre == 2)
		d.raster = init_raster2(d);
	else
		d.raster = init_raster1(d);
	return (d.raster);
}
