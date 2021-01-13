/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 17:53:57 by alebross          #+#    #+#             */
/*   Updated: 2020/06/12 21:02:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	print_selection(t_ray r)
{
	if (r.type == 3)
		putstr("light #");
	else if (r.type == 4)
		putstr("sphere #");
	else if (r.type == 5)
		putstr("plane #");
	else if (r.type == 6)
		putstr("square #");
	else if (r.type == 7)
		putstr("cylinder #");
	else if (r.type == 8)
		putstr("triangle #");
	else if (r.type == 9)
		putstr("pyramide #");
	else if (r.type == 10)
		putstr("cube #");
	putnbrdl(r.id);
}

int		deal_mouse(int c, int x, int y, t_display *d)
{
	t_ray	r;

	if (c == 1)
	{
		r = init_ray(x, y, *d);
		if (r.id)
		{
			d->interface = 1;
			d->id = r.id;
			print_selection(r);
		}
	}
	else if (c == 2)
	{
		d->interface = 2;
		putstr("camera #");
		putnbrdl(d->cx);
	}
	return (0);
}
