/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ambiantlight.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:11:28 by alebross          #+#    #+#             */
/*   Updated: 2020/06/11 11:42:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_obj	get_ambiantlight(char *s)
{
	t_obj			obj;
	unsigned int	i;

	i = 2;
	obj.a.rate = atod(s, &i);
	if (obj.a.rate < 0 || obj.a.rate > 1)
		obj.a.rate = (obj.a.rate < 0 ? 0 : 1);
	obj.a.c = get_colors(s, &i);
	return (obj);
}
