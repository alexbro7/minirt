/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_light_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 17:50:46 by alebross          #+#    #+#             */
/*   Updated: 2020/06/29 23:11:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static int	check_light_line2(char *s, int *i)
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

int			check_light_line(char *s, int *i)
{
	unsigned int	j;
	double			d;

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
	j = (unsigned int)*i;
	if (!(is_double(s, i)))
		return (0);
	d = atod(s, &j);
	if (d < 0.0 || d > 1.0)
		return (3);
	if (!(is_space(s[*i])))
		return (0);
	while (is_space(s[*i]))
		*i += 1;
	return (check_light_line2(s, i));
}
