/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:32:44 by alebross          #+#    #+#             */
/*   Updated: 2020/06/11 11:52:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static int		nbrlen(int nb)
{
	int	len;

	len = (nb ? 1 : 0);
	while (nb > 9)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static void		nb_to_name(char *dest, int nb, int *i, int nm)
{
	int	x;

	x = nbrlen(nm) - nbrlen(nb);
	while (x)
	{
		dest[*i] = '0';
		x--;
		*i += 1;
	}
	x = (nb ? 1 : 0);
	while (nb / x > 9)
		x *= 10;
	while (x)
	{
		dest[*i] = (nb / x) + '0';
		nb %= x;
		x /= 10;
		*i += 1;
	}
}

char			*name_bmp(char *src, int nc, int n)
{
	char	*dest;
	int		size;
	int		i;

	size = ft_strlen(src) - 3;
	i = 0;
	if (!(dest = malloc(sizeof(char) * (size + (nc > 1 ? 5 + nbrlen(nc) : 5)))))
		return (NULL);
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	if (nc > 1)
		nb_to_name(dest, n, &i, nc);
	dest[i] = '.';
	dest[i + 1] = 'b';
	dest[i + 2] = 'm';
	dest[i + 3] = 'p';
	dest[i + 4] = '\0';
	return ((char *)dest);
}
