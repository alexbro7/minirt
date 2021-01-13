/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_n_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 19:34:21 by alebross          #+#    #+#             */
/*   Updated: 2020/06/24 19:02:00 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int		free_n_exit(t_display *d)
{
	lstclear(&d->lst);
	free_raster1(d->raster, d->r.y);
	mlx_destroy_window(d->mlx_ptr, d->win_ptr);
	exit(0);
}
