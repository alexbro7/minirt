/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_camera_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 17:50:08 by alebross          #+#    #+#             */
/*   Updated: 2020/07/01 12:18:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static int	check_camera_line3(char *s, int *i)
{
	unsigned int	j;
	int				d;

	j = *i;
	if (!(is_numeric(s[*i])))
		return (0);
	while (is_numeric(s[*i]))
		*i += 1;
	d = ft_atoi(s, &j);
	if (d < 0 || d > 180)
		return (6);
	if (s[*i])
		return (0);
	return (1);
}

static int	check_camera_line2(char *s, int *i)
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
		j[1]++;
		j[0]++;
	}
	if (!(is_space(s[*i])))
		return (0);
	while (is_space(s[*i]))
		*i += 1;
	return (check_camera_line3(s, i));
}

int			check_camera_line(char *s, int *i)
{
	*i = 1;
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
	return (check_camera_line2(s, i));
}
