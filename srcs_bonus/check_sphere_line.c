/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sphere_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 17:50:32 by alebross          #+#    #+#             */
/*   Updated: 2020/07/01 17:04:25 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static int	check_sphere_line2(char *s, int *i)
{
	int				k[2];
	unsigned int	j;

	j = *i;
	k[1] = 0;
	if (!(is_color(s, i)))
		return (0);
	while (k[1] < 3)
	{
		k[0] = ft_atoi(s, &j);
		if (k[0] < 0 || k[0] > 255)
			return (4);
		k[1]++;
		j++;
	}
	if (s[*i])
		return (0);
	return (1);
}

int			check_sphere_line(char *s, int *i)
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
	if (!(is_double(s, i)))
		return (0);
	if (!(is_space(s[*i])))
		return (0);
	while (is_space(s[*i]))
		*i += 1;
	return (check_sphere_line2(s, i));
}
