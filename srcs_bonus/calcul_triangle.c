/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_triangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 17:49:41 by alebross          #+#    #+#             */
/*   Updated: 2020/06/11 11:32:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_obj	calcul_triangle(t_obj obj)
{
	obj.tr.vec[0] = subvec(obj.tr.pt[1], obj.tr.pt[0]);
	obj.tr.vec[1] = subvec(obj.tr.pt[2], obj.tr.pt[1]);
	obj.tr.vec[2] = subvec(obj.tr.pt[0], obj.tr.pt[2]);
	obj.tr.d = subvec(obj.tr.pt[1], obj.tr.pt[0]);
	obj.tr.d = prdvecto(obj.tr.d, subvec(obj.tr.pt[2], obj.tr.pt[1]));
	obj.tr.d = normalize(obj.tr.d);
	return (obj);
}
