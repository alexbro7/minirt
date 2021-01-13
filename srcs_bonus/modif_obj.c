/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:32:36 by alebross          #+#    #+#             */
/*   Updated: 2020/06/12 21:20:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_d_vector	get_move(int key, double dist)
{
	t_d_vector	v;

	v.x = 0;
	v.y = 0;
	v.z = 0;
	if (key == 0)
		v.x -= dist;
	else if (key == 2)
		v.x += dist;
	else if (key == 1)
		v.z -= dist;
	else if (key == 13)
		v.z += dist;
	else if (key == 12)
		v.y += dist;
	else if (key == 14)
		v.y -= dist;
	return (v);
}

void		get_rotation(int key, int *axe, int *dir)
{
	if (key == 123 || key == 124)
	{
		*axe = 0;
		*dir = (key == 123 ? 1 : -1);
	}
	else if (key == 125 || key == 126)
	{
		*axe = 1;
		*dir = (key == 125 ? -1 : 1);
	}
	else if (key == 43 || key == 47)
	{
		*axe = 2;
		*dir = (key == 43 ? 1 : -1);
	}
}

void		move_obj(t_obj *obj, int type, t_d_vector move)
{
	if (type == 3)
		obj->l.o = addvec(obj->l.o, move);
	else if (type == 4)
		obj->sp.o = addvec(obj->sp.o, move);
	else if (type == 5)
		obj->pl.o = addvec(obj->pl.o, move);
	else if (type == 6)
		obj->sq.o = addvec(obj->sq.o, move);
	else if (type == 7)
		obj->cy.o = addvec(obj->cy.o, move);
	else if (type == 8)
	{
		obj->tr.v = addvec(obj->tr.v, move);
		obj->tr = triangle_rotation(obj->tr, 0, 0);
	}
	else if (type == 9)
		obj->py.o = addvec(obj->py.o, move);
	else if (type == 10)
		obj->cu.o = addvec(obj->cu.o, move);
}

void		rotation_obj(t_obj *obj, int type, int key)
{
	int	axe;
	int	dir;

	get_rotation(key, &axe, &dir);
	if (type == 5)
		obj->pl.d = rotation(obj->pl.d, 9 * dir, axe);
	else if (type == 6)
		obj->sq.d = rotation(obj->sq.d, 9 * dir, axe);
	else if (type == 7)
		obj->cy.d = rotation(obj->cy.d, 9 * dir, axe);
	else if (type == 8)
		obj->tr = triangle_rotation(obj->tr, 9 * dir, axe);
	else if (type == 9)
		obj->py.d = rotation(obj->py.d, 9 * dir, axe);
	else if (type == 10)
		obj->cu.d = rotation(obj->cu.d, 9 * dir, axe);
}

void		modif_obj(int id, int key, t_list *lst)
{
	t_list		*ptr;
	t_obj		(*ptrf[5])(t_obj);

	ptr = lst;
	ptrf[0] = &calcul_square;
	ptrf[1] = &calcul_cylinder;
	ptrf[2] = &calcul_triangle;
	ptrf[3] = &calcul_pyramide;
	ptrf[4] = &calcul_cube;
	while (ptr && ptr->id != id)
		ptr = ptr->next;
	if ((key >= 0 && key <= 2) || (key >= 12 && key <= 14))
		move_obj(&ptr->ctt, ptr->type, get_move(key, 10));
	else if (((key >= 123 && key <= 126)
			|| key == 43 || key == 47) && ptr->type > 4)
		rotation_obj(&ptr->ctt, ptr->type, key);
	if (ptr->type >= 6)
		ptr->ctt = ptrf[ptr->type - 6](ptr->ctt);
}
