/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_cmr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:32:25 by alebross          #+#    #+#             */
/*   Updated: 2020/06/11 11:51:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	modif_cmr1(t_camera *c, int key)
{
	if (key == 0)
		c->o = subvec(c->o, prdvecd(c->d.x, 20));
	else if (key == 2)
		c->o = addvec(c->o, prdvecd(c->d.x, 20));
	else if (key == 1)
		c->o = subvec(c->o, prdvecd(c->d.z, 20));
	else if (key == 13)
		c->o = addvec(c->o, prdvecd(c->d.z, 20));
	else if (key == 12)
		c->o = addvec(c->o, prdvecd(c->d.y, 20));
	else if (key == 14)
		c->o = subvec(c->o, prdvecd(c->d.y, 20));
	else if (key == 123)
		c->d = rotation(c->d, -18, 0);
	else if (key == 124)
		c->d = rotation(c->d, 18, 0);
	else if (key == 125)
		c->d = rotation(c->d, 18, 1);
	else if (key == 126)
		c->d = rotation(c->d, -18, 1);
	else if (key == 43)
		c->d = rotation(c->d, 9, 2);
	else if (key == 47)
		c->d = rotation(c->d, -9, 2);
}

void	modif_cmr(int id, int key, t_list *lst)
{
	t_list	*ptr;

	ptr = lst;
	while (ptr && id)
	{
		if (ptr->type == 2)
			id--;
		if (id)
			ptr = ptr->next;
	}
	modif_cmr1(&ptr->ctt.cmr, key);
}
