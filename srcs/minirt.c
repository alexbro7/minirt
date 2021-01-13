/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:31:59 by alebross          #+#    #+#             */
/*   Updated: 2020/06/28 17:44:03 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static int	check_name(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if (s[i - 3] == '.' && s[i - 2] == 'r' && s[i - 1] == 't')
		return (1);
	putendl("ERROR : Wrong file extension");
	return (0);
}

void		main2(t_display d, char *file, int i)
{
	if (!(init_all(file, 2, &d)))
		return ;
	while (i <= d.cnt_c)
	{
		d.cx = i;
		d.c = lst_cx(d.lst, i);
		if (!(d.raster = init_raster(d)))
		{
			free_raster1(d.raster, d.r.y);
			lstclear(&d.lst);
			return ;
		}
		if (!(save_bmp(d, name_bmp(file, d.cnt_c, i))))
		{
			putendl("ERROR : Can't create bitmap");
			free_raster1(d.raster, d.r.y);
			lstclear(&d.lst);
			return ;
		}
		free_raster1(d.raster, d.r.y);
		i++;
	}
	lstclear(&d.lst);
}

int			main(int ac, char **av)
{
	t_display	d;

	d.mlx_ptr = NULL;
	if (ac == 2 || ac == 3)
	{
		if (!(check_name(av[1])))
			return (0);
		if (ac == 3 && ft_strncmp(av[2], "-save", 5))
		{
			putendl("ERROR : Wrong argument");
			return (0);
		}
		if (ac == 2)
		{
			if (!(init_all(av[1], 1, &d)))
				return (0);
			launch_window(&d);
		}
		else if (ac == 3)
			main2(d, av[1], 1);
	}
	else
		putendl("Wrong number of arguments");
	return (0);
}
