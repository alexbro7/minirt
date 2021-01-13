/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:12:14 by alebross          #+#    #+#             */
/*   Updated: 2020/06/11 11:43:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_obj	get_light(char *s)
{
	t_obj			obj;
	unsigned int	i;

	i = 2;
	obj.l.o = get_position(s, &i);
	obj.l.rate = atod(s, &i);
	if (obj.l.rate < 0 || obj.l.rate > 1)
		obj.l.rate = (obj.l.rate < 0 ? 0 : 1);
	obj.l.c = get_colors(s, &i);
	obj.l.r = absolute(atod(s, &i) * 0.5);
	obj.l.r = (!obj.l.r ? 0.5 : obj.l.r);
	return (obj);
}
