/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:34:06 by alebross          #+#    #+#             */
/*   Updated: 2020/06/23 18:03:16 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static int	write_header(int filesize, t_resolution resolution, int f, int i)
{
	unsigned char	header[54];

	while (i++ < 54 - 1)
		header[i] = 0;
	header[0] = (unsigned char)'B';
	header[1] = (unsigned char)'M';
	header[10] = (unsigned char)54;
	header[14] = (unsigned char)40;
	header[26] = (unsigned char)1;
	header[28] = (unsigned char)32;
	header[2] = (unsigned char)(filesize);
	header[3] = (unsigned char)(filesize >> 8);
	header[4] = (unsigned char)(filesize >> 16);
	header[5] = (unsigned char)(filesize >> 24);
	header[18] = (unsigned char)(resolution.x);
	header[19] = (unsigned char)(resolution.x >> 8);
	header[20] = (unsigned char)(resolution.x >> 16);
	header[21] = (unsigned char)(resolution.x >> 24);
	header[22] = (unsigned char)(resolution.y);
	header[23] = (unsigned char)(resolution.y >> 8);
	header[24] = (unsigned char)(resolution.y >> 16);
	header[25] = (unsigned char)(resolution.y >> 24);
	return (write(f, header, 54) >= 0);
}

int			write_data(int f, t_resolution r, t_ray **w)
{
	t_resolution	i;
	unsigned char	data[4];

	i.y = r.y - 1;
	while (i.y >= 0)
	{
		i.x = 0;
		while (i.x < r.x)
		{
			data[0] = w[i.y][i.x].c.b;
			data[1] = w[i.y][i.x].c.g;
			data[2] = w[i.y][i.x].c.r;
			data[3] = 0;
			if (write(f, data, 4) < 0)
				return (0);
			i.x++;
		}
		i.y--;
	}
	return (1);
}

int			save_bmp(t_display d, const char *filename)
{
	int	f;

	f = open(filename, O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0755);
	if (!(write_header(54 + 3 * d.r.x * d.r.y, d.r, f, 0)))
	{
		putendl("ERROR : Can't write bmp header");
		return (0);
	}
	if (!(write_data(f, d.r, d.raster)))
	{
		putendl("ERROR : Can't write bmp data");
		return (0);
	}
	close(f);
	return (1);
}
