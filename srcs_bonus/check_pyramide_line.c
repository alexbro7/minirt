/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pyramide_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 17:50:14 by alebross          #+#    #+#             */
/*   Updated: 2020/07/01 17:05:32 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static int	check_pyramide_line2(char *s, int *i)
{
	unsigned int	j;
	int				k[2];

	while (is_space(s[*i]))
		*i += 1;
	if (!(is_double(s, i)))
		return (0);
	if (!(is_space(s[*i])))
		return (0);
	while (is_space(s[*i]))
		*i += 1;
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
	return (!s[*i]);
}

static int	check_pyramide_line1(char *s, int *i)
{
	unsigned int	j[2];
	double			d;

	j[0] = *i;
	if (!(is_vector(s, i)))
		return (0);
	j[1] = 0;
	while (j[1] < 3)
	{
		d = atod(s, &j[0]);
		if (d < -1.0 || d > 1.0)
			return (2);
		j[0]++;
		j[1]++;
	}
	if (!(is_space(s[*i])))
		return (0);
	while (is_space(s[*i]))
		*i += 1;
	if (!(is_double(s, i)))
		return (0);
	if (!(is_space(s[*i])))
		return (0);
	return (check_pyramide_line2(s, i));
}

int			check_pyramide_line(char *s, int *i)
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
	return (check_pyramide_line1(s, i));
}
