/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_to_vecvec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:35:07 by alebross          #+#    #+#             */
/*   Updated: 2020/06/11 11:54:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_d_vecvec	vec_to_vecvec(t_d_vector v)
{
	t_d_vecvec	vv;

	vv.z = v;
	vv.y.x = 0;
	vv.y.y = 1;
	vv.y.z = 0;
	vv.x = prdvecto(vv.y, vv.z);
	vv.y = prdvecto(vv.z, vv.x);
	return (vv);
}
