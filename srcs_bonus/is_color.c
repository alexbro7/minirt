/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:29:17 by alebross          #+#    #+#             */
/*   Updated: 2020/06/11 11:48:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	is_color1(char *s, int *i)
{
	if (!(is_numeric(s[*i])))
		return (0);
	while (is_numeric(s[*i]))
		*i += 1;
	return (1);
}

int	is_color(char *s, int *i)
{
	if (!(is_numeric(s[*i])))
		return (0);
	while (is_numeric(s[*i]))
		*i += 1;
	if (s[*i] != ',')
		return (0);
	*i += 1;
	if (is_space(s[*i]))
		while (is_space(s[*i]))
			*i += 1;
	if (!(is_numeric(s[*i])))
		return (0);
	while (is_numeric(s[*i]))
		*i += 1;
	if (s[*i] != ',')
		return (0);
	*i += 1;
	if (is_space(s[*i]))
		while (is_space(s[*i]))
			*i += 1;
	return (is_color1(s, i));
}
