/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 17:49:33 by alebross          #+#    #+#             */
/*   Updated: 2020/06/11 11:32:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_obj	calcul_square(t_obj obj)
{
	obj.sq.pt[0] = addvec(obj.sq.o, prdvecd(obj.sq.d.x, obj.sq.h));
	obj.sq.pt[0] = addvec(obj.sq.pt[0], prdvecd(obj.sq.d.y, obj.sq.h));
	obj.sq.pt[1] = addvec(obj.sq.o, prdvecd(obj.sq.d.x, obj.sq.h));
	obj.sq.pt[1] = subvec(obj.sq.pt[1], prdvecd(obj.sq.d.y, obj.sq.h));
	obj.sq.pt[2] = subvec(obj.sq.o, prdvecd(obj.sq.d.x, obj.sq.h));
	obj.sq.pt[2] = subvec(obj.sq.pt[2], prdvecd(obj.sq.d.y, obj.sq.h));
	obj.sq.pt[3] = subvec(obj.sq.o, prdvecd(obj.sq.d.x, obj.sq.h));
	obj.sq.pt[3] = addvec(obj.sq.pt[3], prdvecd(obj.sq.d.y, obj.sq.h));
	obj.sq.vec[0] = subvec(obj.sq.pt[1], obj.sq.pt[0]);
	obj.sq.vec[1] = subvec(obj.sq.pt[2], obj.sq.pt[1]);
	obj.sq.vec[2] = subvec(obj.sq.pt[3], obj.sq.pt[2]);
	obj.sq.vec[3] = subvec(obj.sq.pt[0], obj.sq.pt[3]);
	return (obj);
}
