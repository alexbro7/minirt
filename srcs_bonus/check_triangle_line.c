/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_triangle_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 17:51:03 by alebross          #+#    #+#             */
/*   Updated: 2020/06/30 16:47:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	check_triangle_line1(char *s, int *i)
{
	unsigned int	j;
	int				k[2];

	j = *i;
	if (!(is_color(s, i)))
		return (0);
	k[0] = 0;
	while (k[0] < 3)
	{
		k[1] = ft_atoi(s, &j);
		if (k[1] < 0 || k[1] > 255)
			return (4);
		j++;
		k[0]++;
	}
	if (s[*i])
		return (0);
	return (1);
}

int	check_triangle_line(char *s, int *i)
{
	*i = 2;
	if (!(is_space(s[*i])))
		return (0);
	while (is_space(s[*i]))
		*i += 1;
	if (!(is_vector(s, i)))
		return (0);
	if (!(is_space(s[*i])))
		return (0);
	while (is_space(s[*i]))
		*i += 1;
	if (!(is_vector(s, i)))
		return (0);
	if (!(is_space(s[*i])))
		return (0);
	while (is_space(s[*i]))
		*i += 1;
	if (!(is_vector(s, i)))
		return (0);
	if (!(is_space(s[*i])))
		return (0);
	while (is_space(s[*i]))
		*i += 1;
	return (check_triangle_line1(s, i));
}
