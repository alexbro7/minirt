/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_idtype.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:12:02 by alebross          #+#    #+#             */
/*   Updated: 2020/06/11 11:42:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static char	**init_idtype(char **idtype)
{
	idtype = malloc(sizeof(char *) * 9);
	idtype[0] = "R ";
	idtype[1] = "A ";
	idtype[2] = "c ";
	idtype[3] = "l ";
	idtype[4] = "sp ";
	idtype[5] = "pl ";
	idtype[6] = "sq ";
	idtype[7] = "cy ";
	idtype[8] = "tr ";
	return (idtype);
}

int			get_idtype(char *s, int l)
{
	char	**idtype;
	int		i;

	idtype = NULL;
	if (!s[0])
		return (-1);
	idtype = init_idtype(idtype);
	i = 0;
	while (i < 9)
	{
		if (ft_strncmp(s, idtype[i], ft_strlen(idtype[i])) == 0)
		{
			free(idtype);
			return (i);
		}
		i++;
	}
	free(idtype);
	free(s);
	error_msg(2, NULL, l, 0);
	exit(0);
}
