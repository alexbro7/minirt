/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_rtfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 17:05:11 by alebross          #+#    #+#             */
/*   Updated: 2020/07/01 17:05:13 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	error_rtfile(int id, int l, int i)
{
	putstr("ERROR : .rt file: L:");
	putnbr(l);
	putstr(" C:");
	putnbrdl(i);
	if (id == 0)
		putendl("\tWrong charactere");
	else if (id == 2)
		putendl("\tDirection components must be in the range [-1.0,1.0]");
	else if (id == 3)
		putendl("\tRate must be in the range [0.0,1.0]");
	else if (id == 4)
		putendl("\tColor components must be in the range [0,255]");
	else if (id == 5)
		putendl("\tResolution components can't be < 1");
	else if (id == 6)
		putendl("\tCamera FOV must be in the range [0,180]");
}
