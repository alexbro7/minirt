/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:32:13 by alebross          #+#    #+#             */
/*   Updated: 2020/06/30 18:43:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdbool.h>
# include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <fcntl.h>
# include "../minilibx_mms_20200219/mlx.h"
# include <math.h>

typedef struct		s_d_vector
{
	double			x;
	double			y;
	double			z;
}					t_d_vector;

typedef struct		s_d_vecvec
{
	t_d_vector		x;
	t_d_vector		y;
	t_d_vector		z;
}					t_d_vecvec;

typedef struct		s_geotools
{
	t_d_vector		l;
	double			ll;
	double			tca;
	double			d;
	double			thc;
}					t_geotools;

typedef struct		s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_color;

typedef struct		s_ray
{
	t_d_vector		o;
	t_d_vector		o1;
	t_d_vector		d;
	int				intersection;
	int				type;
	int				id;
	double			d0;
	double			d1;
	t_d_vector		n;
	t_color			c;
}					t_ray;

typedef struct		s_resolution
{
	int				x;
	int				y;
}					t_resolution;

typedef	struct		s_ambiantlight
{
	double			rate;
	t_color			c;
}					t_ambiantlight;

typedef	struct		s_camera
{
	t_d_vector		o;
	t_d_vecvec		d;
	int				fov;
	int				filtre;
	int				a;
}					t_camera;

typedef	struct		s_light
{
	t_d_vector		o;
	double			rate;
	double			r;
	t_color			c;
}					t_light;

typedef struct		s_sphere
{
	t_d_vector		o;
	double			r;
	t_color			c;
}					t_sphere;

typedef struct		s_plane
{
	t_d_vector		o;
	t_d_vecvec		d;
	t_color			c;
}					t_plane;

typedef struct		s_square
{
	t_d_vector		o;
	t_d_vector		pt[4];
	t_d_vector		vec[4];
	t_d_vecvec		d;
	double			h;
	t_color			c;
}					t_square;

typedef struct		s_cylinder
{
	t_d_vector		o;
	t_d_vecvec		d;
	double			r;
	double			h;
	int				capuchon;
	t_color			c;
}					t_cylinder;

typedef struct		s_triangle
{
	t_d_vector		pt[3];
	t_d_vector		ptinit[3];
	t_d_vector		vec[3];
	t_d_vector		d;
	t_d_vector		v;
	t_d_vecvec		w;
	t_color			c;
}					t_triangle;

typedef struct		s_pyramide
{
	t_d_vector		o;
	t_d_vecvec		d;
	double			r;
	double			h;
	t_d_vector		s;
	t_square		sq;
	t_triangle		tr[4];
	t_color			c;
}					t_pyramide;

typedef struct		s_cube
{
	t_d_vector		o;
	t_d_vecvec		d;
	double			h;
	t_square		sq[6];
	t_color			c;
}					t_cube;

typedef struct		s_lstdata
{
	int				cmr_c;
	int				li_c;
}					t_lstdata;

typedef union		u_obj
{
	t_resolution	r;
	t_ambiantlight	a;
	t_camera		cmr;
	t_light			l;
	t_sphere		sp;
	t_plane			pl;
	t_square		sq;
	t_cylinder		cy;
	t_triangle		tr;
	t_pyramide		py;
	t_cube			cu;
	t_lstdata		data;
}					t_obj;

typedef struct		s_list
{
	int				id;
	int				type;
	t_obj			ctt;
	struct s_list	*next;
}					t_list;

typedef struct		s_display
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_resolution	r;
	t_camera		c;
	int				interface;
	int				id;
	int				cx;
	int				cnt_c;
	t_list			*lst;
	t_ray			**raster;
}					t_display;

char				*name_bmp(char *src, int nc, int n);
int					init_all(char *file, int mode, t_display *d);
int					is_numeric(char c);
int					is_charnb(char *s, int i);
int					is_space(char c);
int					get_idtype(char *s, int l);
double				atod(const char *s, unsigned int *i);
int					ft_atoi(const char *s, unsigned int *i);
int					check_file(int fd);
int					check_res_line(char *s, int *i);
int					check_ambiant_line(char *s, int *i);
int					check_camera_line(char *s, int *i);
int					check_light_line(char *s, int *i);
int					check_sphere_line(char *s, int *i);
int					check_plane_line(char *s, int *i);
int					check_square_line(char *s, int *i);
int					check_cylinder_line(char *s, int *i);
int					check_pyramide_line(char *s, int *i);
int					check_triangle_line(char *s, int *i);
int					is_color(char *s, int *i);
int					is_double(char *s, int *i);
int					is_vector(char *s, int *i);
t_d_vector			clr_to_d(t_color c);
t_color				d_to_clr(t_d_vector d);
double				absolute(double n);
double				norm_eucli(t_d_vector v);
t_color				addcolor(t_color a, t_color b);
t_d_vector			adddir(t_d_vector a, t_d_vector b);
t_d_vector			addvec(t_d_vector a, t_d_vector b);
t_d_vector			subvec(t_d_vector a, t_d_vector b);
t_d_vector			prdvec(t_d_vector a, t_d_vector b);
t_d_vector			prdvecto(t_d_vector a, t_d_vector b);
t_d_vector			prdvecd(t_d_vector a, double d);
t_d_vecvec			vec_to_vecvec(t_d_vector v);
t_d_vecvec			rotation(t_d_vecvec v, double t, int axe);
t_triangle			triangle_rotation(t_triangle t, double angle, int axe);
t_d_vector			get_dir(t_d_vector a, t_d_vector b);
double				prdscal(t_d_vector a, t_d_vector b);
t_d_vector			normalize(t_d_vector v);

t_obj				get_obj(char *s, int type);
t_obj				get_resolution(char *s);
t_obj				get_ambiantlight(char *s);
t_obj				get_camera(char *s);
t_obj				get_light(char *s);
t_obj				get_sphere(char *s);
t_obj				get_plan(char *s);
t_obj				get_square(char *s);
t_obj				get_cylinder(char *s);
t_obj				get_triangle(char *s);
t_obj				get_pyramide(char *s);
t_obj				get_cube(char *s);

t_obj				calcul_square(t_obj obj);
t_obj				calcul_cylinder(t_obj obj);
t_obj				calcul_triangle(t_obj obj);
t_obj				calcul_pyramide(t_obj obj);
t_obj				calcul_cube(t_obj obj);

t_color				get_colors(char *s, unsigned int *i);
t_d_vector			get_position(char *s, unsigned int *i);
t_d_vector			get_orientation(char *s, unsigned int *i);
void				get_lstobj(int fd, t_list **lst);

unsigned int		ft_strlen(char *s);
int					ft_strncmp(char const *s1, char const *s2, unsigned int n);
void				*ft_memcpy(void *dest, const void *src, size_t n);

void				lstadd_back(t_list **alst, t_list *new);
t_list				*lstnew(t_obj content, char **line, t_list **lst);
t_list				*lstlast(t_list *lst);
void				lstclear(t_list **lst);

void				free_raster(t_ray ***raster, int max);

int					open_n_check_file(char *file, t_list **lst);

t_resolution		lst_res(t_list *lst);
t_ambiantlight		lst_a(t_list *lst);
t_camera			lst_cx(t_list *lst, int x);
t_light				lst_lx(t_list *lst, int x);

int					count_lstid(t_list *lst, int id);

t_ray				**init_raster(t_display d);
t_ray				init_ray(int x, int y, t_display d);
t_ray				init_alia_ray(int x, int y, t_display d);
void				load_raster(t_display d);

t_ray				intersec(t_ray r, t_list *lst);
t_ray				intersec_l(t_ray r, t_obj o);
t_ray				intersec_sp(t_ray r, t_obj o);
t_ray				intersec_pl(t_ray r, t_obj o);
t_ray				intersec_sq(t_ray r, t_obj o);
t_ray				intersec_cy(t_ray r, t_obj o);
t_ray				intersec_tr(t_ray r, t_obj o);
t_ray				intersec_py(t_ray r, t_obj o);
t_ray				intersec_cu(t_ray r, t_obj o);
t_color				rapport_shad(t_ray r, t_ambiantlight a, t_list *lst);

void				ft_putchar(int c);
void				putstr(char *s);
void				putendl(char *s);
void				putnbr(int n);
void				putnbrdl(int n);
void				write_lstobj(t_list *lst);

void				launch_window(t_display *d);
void				error_msg(int id, char *str, int nb1, int nb2);
void				error_rtfile(int id, int l, int i);

int					deal_key(int key, t_display *d);
int					deal_mouse(int c, int x, int y, t_display *d);
void				modif_cmr(int id, int key, t_list *lst);
void				modif_obj(int id, int key, t_list *lst);

int					free_n_exit(t_display *d);
void				free_raster1(t_ray **raster, int a);
int					save_bmp(t_display d, const char *filename);
int					color_to_int(t_color c);

#endif
