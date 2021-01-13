/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_n_check_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:33:06 by alebross          #+#    #+#             */
/*   Updated: 2020/06/23 17:22:05 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	open_n_check_file2(char *file, t_list **lst)
{
	int		fd;

	if ((fd = open(file, O_RDONLY)) == -1)
	{
		error_msg(1, file, 0, 0);
		return (0);
	}
	get_lstobj(fd, lst);
	if (close(fd == -1))
	{
		error_msg(4, file, 0, 0);
		lstclear(lst);
		return (0);
	}
	return (1);
}

int	open_n_check_file(char *file, t_list **lst)
{
	int		b;
	int		fd;

	b = 1;
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		error_msg(1, file, 0, 0);
		return (0);
	}
	b = check_file(fd);
	if (close(fd) == -1)
	{
		error_msg(4, file, 0, 0);
		return (0);
	}
	if (b)
		return (open_n_check_file2(file, lst));
	return (0);
}
