/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:13:47 by alebross          #+#    #+#             */
/*   Updated: 2020/06/28 16:08:32 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static t_resolution	adjust(t_resolution r)
{
	t_resolution max;

	mlx_get_screen_size(mlx_init(), &max.x, &max.y);
	r.x = (r.x > max.x ? max.x : r.x);
	r.y = (r.y > max.y ? max.y : r.y);
	return (r);
}

static int			init_all1(t_display *d)
{
	d->c = lst_cx(d->lst, d->cx);
	if (!(d->raster = init_raster(*d)))
	{
		lstclear(&d->lst);
		return (0);
	}
	d->interface = 2;
	return (1);
}

int					init_all(char *file, int mode, t_display *d)
{
	if (!(open_n_check_file(file, &d->lst)))
		return (0);
	if (lst_res(d->lst).x < 1 || lst_res(d->lst).y < 1)
	{
		putendl("ERROR : Impossible resolution (< 1).");
		lstclear(&d->lst);
		return (0);
	}
	d->cnt_c = lstlast(d->lst)->ctt.data.cmr_c;
	d->r = (mode == 1 ? adjust(lst_res(d->lst)) : lst_res(d->lst));
	d->cx = 1;
	return (init_all1(d));
}
