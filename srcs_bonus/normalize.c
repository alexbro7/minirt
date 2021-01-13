/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:33:00 by alebross          #+#    #+#             */
/*   Updated: 2020/06/11 11:52:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_d_vector	normalize(t_d_vector v)
{
	double	n;

	n = 1 / norm_eucli(v);
	v.x *= n;
	v.y *= n;
	v.z *= n;
	return (v);
}
