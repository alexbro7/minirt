/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:13:01 by alebross          #+#    #+#             */
/*   Updated: 2020/06/11 11:44:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_obj	get_resolution(char *s)
{
	t_obj			obj;
	unsigned int	i;

	i = 2;
	obj.r.x = ft_atoi(s, &i);
	obj.r.y = ft_atoi(s, &i);
	return (obj);
}
