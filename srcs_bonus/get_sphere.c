/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:13:13 by alebross          #+#    #+#             */
/*   Updated: 2020/06/11 11:44:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_obj	get_sphere(char *s)
{
	unsigned int	i;
	t_obj			obj;

	i = 3;
	obj.sp.o = get_position(s, &i);
	obj.sp.r = absolute(atod(s, &i) * 0.5);
	obj.sp.c = get_colors(s, &i);
	return (obj);
}
