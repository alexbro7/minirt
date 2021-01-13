/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_res_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 17:50:54 by alebross          #+#    #+#             */
/*   Updated: 2020/07/01 12:11:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int			check_res_line(char *s, int *i)
{
	*i = 1;
	if (!(is_space(s[*i])))
		return (0);
	while (is_space(s[*i]))
		*i += 1;
	if (!(is_numeric(s[*i])))
		return (0);
	while (is_numeric(s[*i]))
		*i += 1;
	if (!(is_space(s[*i])))
		return (0);
	while (is_space(s[*i]))
		*i += 1;
	if (!(is_numeric(s[*i])))
		return (0);
	while (is_numeric(s[*i]))
		*i += 1;
	return (!s[*i]);
}
