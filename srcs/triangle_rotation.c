/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_rotation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:34:48 by alebross          #+#    #+#             */
/*   Updated: 2020/06/11 11:54:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_triangle	triangle_rotation(t_triangle t, double angle, int axe)
{
	t.w = rotation(t.w, angle, axe);
	t.pt[0] = addvec(addvec(addvec(prdvecd(t.w.x, t.ptinit[0].x),
		prdvecd(t.w.y, t.ptinit[0].y)), prdvecd(t.w.z, t.ptinit[0].z)), t.v);
	t.pt[1] = addvec(addvec(addvec(prdvecd(t.w.x, t.ptinit[1].x),
		prdvecd(t.w.y, t.ptinit[1].y)), prdvecd(t.w.z, t.ptinit[1].z)), t.v);
	t.pt[2] = addvec(addvec(addvec(prdvecd(t.w.x, t.ptinit[2].x),
		prdvecd(t.w.y, t.ptinit[2].y)), prdvecd(t.w.z, t.ptinit[2].z)), t.v);
	return (t);
}
