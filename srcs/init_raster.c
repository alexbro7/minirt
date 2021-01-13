/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raster.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:14:11 by alebross          #+#    #+#             */
/*   Updated: 2020/06/11 11:45:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_ray		**init_raster1(t_display d)
{
	t_resolution	i;

	i.y = 0;
	while (i.y < d.r.y)
	{
		i.x = 0;
		while (i.x < d.r.x)
		{
			d.raster[i.y][i.x] = init_ray(i.x, i.y, d);
			i.x++;
		}
		i.y++;
	}
	return (d.raster);
}

t_ray		**init_raster(t_display d)
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
	d.raster = init_raster1(d);
	return (d.raster);
}
