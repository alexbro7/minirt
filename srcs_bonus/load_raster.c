/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_raster.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:29:57 by alebross          #+#    #+#             */
/*   Updated: 2020/06/11 11:49:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	load_raster(t_display d)
{
	t_resolution	i;

	i.y = 0;
	while (i.y < d.r.y)
	{
		i.x = 0;
		while (i.x < d.r.x)
		{
			mlx_pixel_put(d.mlx_ptr, d.win_ptr, i.x, i.y,
			color_to_int(d.raster[i.y][i.x].c));
			i.x++;
		}
		i.y++;
	}
}
