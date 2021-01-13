/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:29:47 by alebross          #+#    #+#             */
/*   Updated: 2020/06/24 19:02:31 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	launch_window(t_display *d)
{
	d->mlx_ptr = mlx_init();
	d->win_ptr = mlx_new_window(d->mlx_ptr, d->r.x, d->r.y, "miniRT");
	d->interface = 2;
	if (!d->win_ptr)
	{
		putendl("ERROR : Can't open window.");
		free_n_exit(d);
	}
	load_raster(*d);
	putendl("camera #1");
	mlx_key_hook(d->win_ptr, deal_key, d);
	mlx_mouse_hook(d->win_ptr, deal_mouse, d);
	mlx_hook(d->win_ptr, 17, 1L << 17, free_n_exit, d);
	mlx_loop(d->mlx_ptr);
}
