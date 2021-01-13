/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 17:51:15 by alebross          #+#    #+#             */
/*   Updated: 2020/06/30 18:42:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static int	check_liste(int *cnt)
{
	if (cnt[0] != 1)
	{
		putendl("ERROR : Need 1 resolution.");
		return (0);
	}
	if (cnt[1] != 1)
	{
		putendl("ERROR : Need 1 ambiant light.");
		return (0);
	}
	if (!cnt[2])
	{
		putendl("ERROR : No camera.");
		return (0);
	}
	return (1);
}

static int	check_line(char *line, int l, int type)
{
	int	i;
	int e;
	int	(*ptr[11])(char *s, int *i);

	ptr[0] = &check_res_line;
	ptr[1] = &check_ambiant_line;
	ptr[2] = &check_camera_line;
	ptr[3] = &check_light_line;
	ptr[4] = &check_sphere_line;
	ptr[5] = &check_plane_line;
	ptr[6] = &check_square_line;
	ptr[7] = &check_cylinder_line;
	ptr[8] = &check_triangle_line;
	ptr[9] = &check_pyramide_line;
	ptr[10] = &check_square_line;
	if (type == -1)
		return (1);
	if ((e = ptr[type](line, &i)) != 1)
	{
		error_rtfile(e, l, i);
		free(line);
		return (0);
	}
	return (1);
}

static int	type_range(int n)
{
	if (n == -1)
		return (0);
	if (n == 0 || n == 1)
		return (1);
	if (n == 2 || n == 3)
		return (2);
	if (n >= 4 && n <= 10)
		return (3);
	return (-1);
}

static int	check_sep(int a, int b, char *line, int i)
{
	a = type_range(a);
	b = type_range(b);
	if (a != b && a != 0 && b != 0)
	{
		free(line);
		error_msg(7, NULL, i, 0);
		return (0);
	}
	return (1);
}

int			check_file(int fd)
{
	char	*line;
	int		i[2];
	int		cnt[3];
	int		type[2];

	i[0] = 1;
	i[1] = 1;
	cnt[0] = 0;
	cnt[1] = 0;
	cnt[2] = 0;
	type[0] = -1;
	while (i[1])
	{
		i[1] = get_next_line(fd, &line);
		type[1] = get_idtype(line, i[0]);
		if (!(check_sep(type[0], type[1], line, i[0]))
			|| !(check_line(line, i[0], type[1])))
			return (0);
		if (type[1] >= 0 && type[1] <= 2)
			cnt[type[1]]++;
		type[0] = type[1];
		free(line);
		i[0]++;
	}
	return (check_liste(cnt));
}
