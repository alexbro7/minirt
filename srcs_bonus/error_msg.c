/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 17:54:08 by alebross          #+#    #+#             */
/*   Updated: 2020/06/17 14:17:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	error_msg3(int id, char *str, int nb1, int nb2)
{
	if (id == 8)
	{
		putstr("ERROR : can't create ");
		putstr(str);
		putendl(".bmp\n");
	}
	else if (id == 9)
	{
		putstr("ERROR : can't malloc lst ");
		if (nb1 == 0)
			putstr("resolution\n");
		else if (nb1 == 1)
			putstr("ambiant light\n");
		else
		{
			putstr("obj ");
			putnbrdl(nb2);
		}
	}
}

void	error_msg2(int id, char *str, int nb1, int nb2)
{
	if (id == 5)
	{
		putstr("ERROR : Can't malloc raster[");
		putnbr(nb1);
		putendl("]");
	}
	else if (id == 6)
	{
		putstr("ERROR : Can't malloc raster[");
		putnbr(nb1);
		putstr("]");
	}
	else if (id == 7)
	{
		putstr("ERROR : L");
		putnbr(nb1);
		putendl(": differents kind of objetcs must be separate by empty line");
	}
	else
		error_msg3(id, str, nb1, nb2);
}

void	error_msg(int id, char *str, int nb1, int nb2)
{
	if (id == 1)
	{
		putstr("ERROR : Can't open ");
		putendl(str);
	}
	else if (id == 2)
	{
		putstr("ERROR : Wrong id. L:");
		putnbrdl(nb1);
	}
	else if (id == 3)
	{
		putstr("ERROR : Wrong char in the rt file .L");
		putnbr(nb1);
		putstr(" C:");
		putnbrdl(nb2);
	}
	else if (id == 4)
	{
		putstr("ERROR : Can't close ");
		putendl(str);
	}
	else
		error_msg2(id, str, nb1, nb2);
}
