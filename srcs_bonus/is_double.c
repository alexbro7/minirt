/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 19:38:46 by alebross          #+#    #+#             */
/*   Updated: 2020/06/11 11:48:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int		is_double(char *s, int *i)
{
	if (!(is_numeric(s[*i])))
		return (0);
	while (is_numeric(s[*i]))
		*i += 1;
	if (s[*i] == '.')
	{
		*i += 1;
		if (!(is_numeric(s[*i])))
			return (0);
		while (is_numeric(s[*i]))
			*i += 1;
	}
	return (1);
}
