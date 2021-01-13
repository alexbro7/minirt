/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 17:53:51 by alebross          #+#    #+#             */
/*   Updated: 2020/06/24 18:59:06 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

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
	return (0);
}
