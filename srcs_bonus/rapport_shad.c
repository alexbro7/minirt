/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rapport_shad.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:33:52 by alebross          #+#    #+#             */
/*   Updated: 2020/06/23 21:06:58 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_color		add_l(t_ray r, t_light l, t_color c)
{
	t_d_vector	clr;

	l.c.r = (l.c.r > c.r ? c.r : l.c.r);
	l.c.g = (l.c.g > c.g ? c.g : l.c.g);
	l.c.b = (l.c.b > c.b ? c.b : l.c.b);
	clr = clr_to_d(l.c);
	clr = prdvecd(clr, l.rate);
	clr = prdvecd(clr, absolute(prdscal(r.n, r.d)));
	r.d0 /= 300;
	clr.x /= 1 + r.d0;
	clr.y /= 1 + r.d0;
	clr.z /= 1 + r.d0;
	clr = addvec(clr, clr_to_d(c));
	clr.x = (clr.x > 1 ? 1 : clr.x);
	clr.y = (clr.y > 1 ? 1 : clr.y);
	clr.z = (clr.z > 1 ? 1 : clr.z);
	return (d_to_clr(clr));
}

t_ray		light_touch(t_ray r, t_light l, t_list *lst,
						t_ray (**ptr)(t_ray, t_obj))
{
	t_ray		tmp;
	t_d_vector	p;

	p = addvec(r.o1, prdvecd(r.n, 0.000001));
	r.o = p;
	r.d = get_dir(r.o, l.o);
	r.intersection = 0;
	r.d0 = norm_eucli(subvec(r.o, l.o));
	while (lst->next)
	{
		if (lst->type > 3 && lst->type < 11)
			tmp = ptr[lst->type - 4](r, lst->ctt);
		if (lst->type > 3 && lst->type < 11)
			if (tmp.intersection && tmp.d0 >= 0 && tmp.d0 < r.d0)
				return (r);
		lst = lst->next;
	}
	r.intersection = 1;
	return (r);
}

t_ray		light_touch0(t_ray r, t_light l, t_list *lst)
{
	t_ray		(*ptr[7])(t_ray r, t_obj o);

	ptr[0] = &intersec_sp;
	ptr[1] = &intersec_pl;
	ptr[2] = &intersec_sq;
	ptr[3] = &intersec_cy;
	ptr[4] = &intersec_tr;
	ptr[5] = &intersec_py;
	ptr[6] = &intersec_cu;
	return (light_touch(r, l, lst, ptr));
}

t_color		add_lights(t_ray r, t_list *lst, int cnt_l)
{
	int			i;
	t_light		l;
	t_ray		tmp;

	i = 1;
	while (i <= cnt_l)
	{
		l = lst_lx(lst, i);
		tmp = light_touch0(r, l, lst);
		if (tmp.intersection)
		{
			r.c = add_l(tmp, l, r.c);
		}
		i++;
	}
	return (r.c);
}

t_color		rapport_shad(t_ray r, t_ambiantlight a, t_list *lst)
{
	t_d_vector	clr;
	t_color		clamp;

	clamp = r.c;
	clr = clr_to_d(r.c);
	clr = prdvec(clr, prdvecd(clr_to_d(a.c), a.rate));
	r.c = d_to_clr(clr);
	r.c = add_lights(r, lst, lstlast(lst)->ctt.data.li_c);
	return (r.c);
}
