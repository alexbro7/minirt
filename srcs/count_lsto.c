/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_lsto.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 17:51:55 by alebross          #+#    #+#             */
/*   Updated: 2020/06/11 11:35:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	count_lstid(t_list *lst, int id)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (lst->type == id)
			i++;
		lst = lst->next;
	}
	return (i);
}
