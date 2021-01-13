/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_to_clr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 17:52:18 by alebross          #+#    #+#             */
/*   Updated: 2020/06/11 11:35:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_color		d_to_clr(t_d_vector d)
{
	t_color		r;
	double		tmp;

	tmp = d.x * 255;
	tmp = (tmp > 255 ? 255 : tmp);
	tmp = (tmp < 0 ? 0 : tmp);
	r.r = tmp;
	tmp = d.y * 255;
	tmp = (tmp > 255 ? 255 : tmp);
	tmp = (tmp < 0 ? 0 : tmp);
	r.g = tmp;
	tmp = d.z * 255;
	tmp = (tmp > 255 ? 255 : tmp);
	tmp = (tmp < 0 ? 0 : tmp);
	r.b = tmp;
	return (r);
}
