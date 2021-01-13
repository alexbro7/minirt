/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 17:53:51 by alebross          #+#    #+#             */
/*   Updated: 2020/06/17 18:10:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	deal_moves(int key, t_display *d)
{
	if (d->interface == 2)
	{
		modif_cmr(d->cx, key, d->lst);
		d->c = lst_cx(d->lst, d->cx);
	}
	else if (d->interface == 1)
		modif_obj(d->id, key, d->lst);
	free_raster1(d->raster, d->r.y);
	if (!(d->raster = init_raster(*d)))
	{
		lstclear(&d->lst);
		exit(0);
	}
	load_raster(*d);
}

void	switch_camera(int key, t_display *d)
{
	if (key == 7 && d->cx < d->cnt_c)
		d->cx++;
	else if (key == 7 && d->cx == d->cnt_c)
		d->cx = 1;
	else if (key == 6 && d->cx > 1)
		d->cx--;
	else if (key == 6 && d->cx == 1)
		d->cx = d->cnt_c;
	d->c = lst_cx(d->lst, d->cx);
	d->interface = 2;
	free_raster1(d->raster, d->r.y);
	if (!(d->raster = init_raster(*d)))
	{
		lstclear(&d->lst);
		exit(0);
	}
	load_raster(*d);
	putstr("camera #");
	putnbrdl(d->cx);
}

int		deal_key(int key, t_display *d)
{
	if (key == 53)
		free_n_exit(d);
	else if (key == 6 || key == 7)
		switch_camera(key, d);
	else if ((key >= 0 && key <= 3) || (key >= 12 && key <= 14)
		|| (key >= 123 && key <= 126) || key == 43 || key == 47)
		deal_moves(key, d);
	return (0);
}
