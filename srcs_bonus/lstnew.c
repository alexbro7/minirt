/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:31:50 by alebross          #+#    #+#             */
/*   Updated: 2020/06/21 15:26:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_list	*lstnew(t_obj content, char **line, t_list **lst)
{
	t_list	*new;

	if (!(new = malloc(sizeof(t_list*) + sizeof(t_obj) + (2 * sizeof(int)))))
	{
		free(line);
		lstclear(lst);
		exit(0);
	}
	new->ctt = content;
	new->next = NULL;
	return (new);
}
