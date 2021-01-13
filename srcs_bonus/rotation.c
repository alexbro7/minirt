/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:33:59 by alebross          #+#    #+#             */
/*   Updated: 2020/06/11 11:54:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_d_vecvec	rotation(t_d_vecvec v, double t, int axe)
{
	t_d_vecvec	w;

	w.x.x = 0;
	t *= 0.017453292519943295;
	if (axe == 0)
	{
		w.x = subvec(prdvecd(v.x, cos(t)), prdvecd(v.z, sin(t)));
		w.y = v.y;
		w.z = addvec(prdvecd(v.z, cos(t)), prdvecd(v.x, sin(t)));
	}
	else if (axe == 1)
	{
		w.x = v.x;
		w.y = addvec(prdvecd(v.y, cos(t)), prdvecd(v.z, sin(t)));
		w.z = subvec(prdvecd(v.z, cos(t)), prdvecd(v.y, sin(t)));
	}
	else if (axe == 2)
	{
		w.x = addvec(prdvecd(v.x, cos(t)), prdvecd(v.y, sin(t)));
		w.y = addvec(prdvecd(v.x, (sin(t) * -1)), prdvecd(v.y, cos(t)));
		w.z = v.z;
	}
	return (w);
}
