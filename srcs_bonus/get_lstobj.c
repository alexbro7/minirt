/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lstobj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:12:24 by alebross          #+#    #+#             */
/*   Updated: 2020/06/23 18:22:36 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static t_obj	get_data_liste(t_list *lst)
{
	t_obj	o;

	o.data.li_c = count_lstid(lst, 3);
	o.data.cmr_c = count_lstid(lst, 2);
	return (o);
}

void			get_lstobj(int fd, t_list **lst)
{
	char		*line;
	int			b[2];
	int			type;

	b[0] = 1;
	b[1] = 1;
	*lst = NULL;
	while (b[0] > -1)
	{
		b[0] = get_next_line(fd, &line);
		b[0] = (b[0] == 0 ? -1 : 1);
		type = get_idtype(line, 0);
		if (type != -1)
		{
			lstadd_back(lst, lstnew(get_obj(line, type), &line, lst));
			lstlast(*lst)->type = type;
			if (type > 2)
				lstlast(*lst)->id = b[1];
			if (type > 2)
				b[1]++;
		}
		free(line);
	}
	lstadd_back(lst, lstnew(get_data_liste(*lst), &line, lst));
	lstlast(*lst)->type = -2;
}
