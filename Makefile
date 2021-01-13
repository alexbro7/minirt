# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alebross <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/11 23:31:04 by alebross          #+#    #+#              #
#    Updated: 2020/06/30 18:45:16 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	miniRT
FLAGS		=	-Wall -Wextra -Werror
SRCS		=	srcs/absolute.c \
		srcs/adddir.c \
		srcs/addvec.c \
		srcs/atod.c \
		srcs/calcul_cylinder.c \
		srcs/calcul_square.c \
		srcs/calcul_triangle.c \
		srcs/check_ambiant_line.c \
		srcs/check_camera_line.c \
		srcs/check_cylinder_line.c \
		srcs/check_file.c \
		srcs/check_light_line.c \
		srcs/check_plane_line.c \
		srcs/check_res_line.c \
		srcs/check_sphere_line.c \
		srcs/check_square_line.c \
		srcs/check_triangle_line.c \
		srcs/clr_to_d.c \
		srcs/color_to_int.c \
		srcs/count_lsto.c \
		srcs/d_to_clr.c \
		srcs/deal_key.c \
		srcs/error_msg.c \
		srcs/error_rtfile.c \
		srcs/free_n_exit.c \
		srcs/free_raster.c \
		srcs/ft_atoi.c \
		srcs/ft_memcpy.c \
		srcs/ft_strlen.c \
		srcs/ft_strncmp.c \
		srcs/get_ambiantlight.c \
		srcs/get_camera.c \
		srcs/get_cylinder.c \
		srcs/get_dir.c \
		srcs/get_idtype.c \
		srcs/get_light.c \
		srcs/get_lstobj.c \
		srcs/get_next_line.c \
		srcs/get_next_line_utils.c \
		srcs/get_obj.c \
		srcs/get_plan.c \
		srcs/get_resolution.c \
		srcs/get_sphere.c \
		srcs/get_square.c \
		srcs/get_triangle.c \
		srcs/init_all.c \
		srcs/init_raster.c \
		srcs/init_ray.c \
		srcs/intersec.c \
		srcs/intersec_cy.c \
		srcs/intersec_l.c \
		srcs/intersec_pl.c \
		srcs/intersec_sp.c \
		srcs/intersec_sq.c \
		srcs/intersec_tr.c \
		srcs/is_charnb.c \
		srcs/is_color.c \
		srcs/is_double.c \
		srcs/is_numeric.c \
		srcs/is_space.c \
		srcs/is_vector.c \
		srcs/launch_window.c \
		srcs/load_raster.c \
		srcs/lst_a.c \
		srcs/lst_cx.c \
		srcs/lst_lx.c \
		srcs/lst_res.c \
		srcs/lstadd_back.c \
		srcs/lstclear.c \
		srcs/lstlast.c \
		srcs/lstnew.c \
		srcs/minirt.c \
		srcs/name_bmp.c \
		srcs/norm_eucli.c \
		srcs/normalize.c \
		srcs/open_n_check_file.c \
		srcs/prdscal.c \
		srcs/prdvec.c \
		srcs/prdvecd.c \
		srcs/prdvecto.c \
		srcs/put.c \
		srcs/rapport_shad.c \
		srcs/rotation.c \
		srcs/save_bmp.c \
		srcs/subvec.c \
		srcs/triangle_rotation.c \
		srcs/vec_to_vecvec.c \

SRCSBNS		=	srcs_bonus/absolute.c \
		srcs_bonus/addcolor.c \
		srcs_bonus/adddir.c \
		srcs_bonus/addvec.c \
		srcs_bonus/atod.c \
		srcs_bonus/calcul_cube.c \
		srcs_bonus/calcul_cylinder.c \
		srcs_bonus/calcul_pyramide.c \
		srcs_bonus/calcul_square.c \
		srcs_bonus/calcul_triangle.c \
		srcs_bonus/check_ambiant_line.c \
		srcs_bonus/check_camera_line.c \
		srcs_bonus/check_cylinder_line.c \
		srcs_bonus/check_file.c \
		srcs_bonus/check_light_line.c \
		srcs_bonus/check_plane_line.c \
		srcs_bonus/check_pyramide_line.c \
		srcs_bonus/check_res_line.c \
		srcs_bonus/check_sphere_line.c \
		srcs_bonus/check_square_line.c \
		srcs_bonus/check_triangle_line.c \
		srcs_bonus/clr_to_d.c \
		srcs_bonus/color_to_int.c \
		srcs_bonus/count_lsto.c \
		srcs_bonus/d_to_clr.c \
		srcs_bonus/deal_key.c \
		srcs_bonus/deal_mouse.c \
		srcs_bonus/error_msg.c \
		srcs_bonus/error_rtfile.c \
		srcs_bonus/free_n_exit.c \
		srcs_bonus/free_raster.c \
		srcs_bonus/ft_atoi.c \
		srcs_bonus/ft_memcpy.c \
		srcs_bonus/ft_strlen.c \
		srcs_bonus/ft_strncmp.c \
		srcs_bonus/get_ambiantlight.c \
		srcs_bonus/get_camera.c \
		srcs_bonus/get_cube.c \
		srcs_bonus/get_cylinder.c \
		srcs_bonus/get_dir.c \
		srcs_bonus/get_idtype.c \
		srcs_bonus/get_light.c \
		srcs_bonus/get_lstobj.c \
		srcs_bonus/get_next_line.c \
		srcs_bonus/get_next_line_utils.c \
		srcs_bonus/get_obj.c \
		srcs_bonus/get_plan.c \
		srcs_bonus/get_pyramide.c \
		srcs_bonus/get_resolution.c \
		srcs_bonus/get_sphere.c \
		srcs_bonus/get_square.c \
		srcs_bonus/get_triangle.c \
		srcs_bonus/init_alia_ray.c \
		srcs_bonus/init_all.c \
		srcs_bonus/init_raster.c \
		srcs_bonus/init_ray.c \
		srcs_bonus/intersec.c \
		srcs_bonus/intersec_cu.c \
		srcs_bonus/intersec_cy.c \
		srcs_bonus/intersec_l.c \
		srcs_bonus/intersec_pl.c \
		srcs_bonus/intersec_py.c \
		srcs_bonus/intersec_sp.c \
		srcs_bonus/intersec_sq.c \
		srcs_bonus/intersec_tr.c \
		srcs_bonus/is_charnb.c \
		srcs_bonus/is_color.c \
		srcs_bonus/is_double.c \
		srcs_bonus/is_numeric.c \
		srcs_bonus/is_space.c \
		srcs_bonus/is_vector.c \
		srcs_bonus/launch_window.c \
		srcs_bonus/load_raster.c \
		srcs_bonus/lst_a.c \
		srcs_bonus/lst_cx.c \
		srcs_bonus/lst_lx.c \
		srcs_bonus/lst_res.c \
		srcs_bonus/lstadd_back.c \
		srcs_bonus/lstclear.c \
		srcs_bonus/lstlast.c \
		srcs_bonus/lstnew.c \
		srcs_bonus/minirt.c \
		srcs_bonus/modif_cmr.c \
		srcs_bonus/modif_obj.c \
		srcs_bonus/name_bmp.c \
		srcs_bonus/norm_eucli.c \
		srcs_bonus/normalize.c \
		srcs_bonus/open_n_check_file.c \
		srcs_bonus/prdscal.c \
		srcs_bonus/prdvec.c \
		srcs_bonus/prdvecd.c \
		srcs_bonus/prdvecto.c \
		srcs_bonus/put.c \
		srcs_bonus/rapport_shad.c \
		srcs_bonus/rotation.c \
		srcs_bonus/save_bmp.c \
		srcs_bonus/subvec.c \
		srcs_bonus/triangle_rotation.c \
	 	srcs_bonus/vec_to_vecvec.c \
		
OBJS		=	$(SRCS:.c=.o)

OBJSBNS		=	$(SRCSBNS:.c=.o)

MLX			=	libmlx.dylib

PATHINC		=	includes/

all		: $(NAME)

$(NAME)	:	$(OBJS)
			clang $(FLAGS) -o $(NAME) $(OBJS) $(MLX) -I $(PATHINC)

bonus	:	$(OBJSBNS)
			clang $(FLAGS) -o $(NAME) $(OBJSBNS) $(MLX) -I $(PATHINC)

clean	:
			rm -f $(OBJS) $(OBJSBNS)

fclean	:	clean
			rm -f $(NAME)

%.o 	:	%.c
		clang ${FLAGS} -c $< -o $@
re		: fclean all

.PHONY	: all clean fclean re
