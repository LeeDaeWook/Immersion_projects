/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:59:14 by siyang            #+#    #+#             */
/*   Updated: 2023/06/17 22:39:23 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <fcntl.h>
// open
# include <unistd.h>
// close, read, write
# include <stdio.h>
// printf, perror, strerror
# include <stdlib.h>
// malloc, free, exit
# include <math.h>
# include <stdbool.h>
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include "generic_lst.h"
# include "vector.h"

# define ERROR -1

# define WIDTH 1600.0
# define HEIGHT 900.0
# define EPSILON 1e-6
# define T_MIN EPSILON
# define T_MAX HUGE_VAL
# define PI 3.1415926535897932385

# define RANDOM_A 1103515245
# define RANDOM_C 12345
# define RANDOM_M 2147483648

# define SPEC_SHININESS 32
# define SPEC_STRENGTH 0.5
# define LUMEN 1

# define ON 1
# define OFF 0

// W
# define FORWARD 13
// S
# define BACKWARD 1
// A
# define LEFT 0
// D
# define RIGHT 2
// Q
# define UP 12
// E
# define DOWN 14
// up arrow
# define TILT_UP 126
// down arrow
# define TILT_DOWN 125
// left arrow
# define PAN_LEFT 123
// right arrow
# define PAN_RIGHT 124
// 1
# define LIGHT 18
// 2
# define RESOLUTION 19
// 3
# define AA 20

enum e_type
{
	SP,
	PL,
	CY,
	CO,
	A,
	C,
	L
};

typedef struct s_ambient
{
	double		ratio;
	t_color3	color;
}	t_ambient;

typedef struct s_camera
{
	t_point3	coord;
	t_vec3		vec;
	int			fov;
	double		viewport_h;
	double		viewport_w;
	t_vec3		horizontal;
	t_vec3		vertical;
	double		focal_length;
	t_point3	lower_left_corner;
	t_vec3		w;
	t_vec3		u;
	t_vec3		v;
}	t_camera;

typedef struct s_light
{
	t_generic_lst	*next;
	double			ratio;
	t_point3		coord;
	t_color3		color;
}	t_light;

typedef struct s_sphere
{
	t_generic_lst	*next;
	int				id;
	t_point3		coord;
	double			radius;
	t_color3		color;
}	t_sphere;

typedef struct s_plane
{
	t_generic_lst	*next;
	int				id;
	t_point3		coord;
	t_vec3			vec;
	t_color3		color;
}	t_plane;

typedef struct s_cylinder
{
	t_generic_lst	*next;
	int				id;
	t_point3		coord;
	t_vec3			vec;
	double			diameter;
	double			height;
	t_color3		color;
}	t_cylinder;

typedef struct s_cone
{
	t_generic_lst	*next;
	int				id;
	t_point3		base_center;
	t_vec3			vec;
	double			diameter;
	double			height;
	t_color3		color;
}	t_cone;

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
}	t_img;

typedef struct s_texture
{
	double		u;
	double		v;
}	t_texture;

typedef struct s_ray
{
	t_point3	origin;
	t_vec3		direction;
}	t_ray;

typedef struct s_hit_record
{
	t_point3	p;
	t_vec3		normal;
	double		t;
	bool		front_face;
	t_color3	color;
}	t_hit_record;

typedef struct s_screen
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	int		resolution;
}	t_screen;

typedef struct s_scene
{
	t_ambient		a;
	t_camera		c;
	t_light			*l_lst;
	t_generic_lst	*obj_lst;
	t_screen		*screen;
	int				samples;
	bool			lighting;
}	t_scene;

// main.c
void	init(t_scene *scene, t_screen *screen);
void	render(t_scene *scene, t_screen *screen);

// utils.c
void	error_exit(char *msg, int code);
double	degrees_to_radians(double degrees);
double	random_double(int seed);
double	clamp(double x, double min, double max);
t_vec3	vector_clamp(t_vec3 vec, double min, double max);

// ft_atof.c
double	ft_atof(const char *str);
double	make_double(const char *str, int *len);

// parser.c
void	parser(int fd, t_scene *scene);
void	init_parser(void (*fp[7])(t_scene *, char *));
int		scan_id(char *str);
void	a_parser(t_scene *scene, char *line);
void	c_parser(t_scene *scene, char *line);
void	l_parser(t_scene *scene, char *line);
void	sp_parser(t_scene *scene, char *line);
void	pl_parser(t_scene *scene, char *line);
void	cy_parser(t_scene *scene, char *line);
void	co_parser(t_scene *scene, char *line);

// parser_utils.c
double		get_float(char **line);
t_color3	get_color(char **line);
int			get_fov(char **line);
t_point3	get_coordinate(char **line);
t_vec3		get_vector(char **line);
int 		validate_argument(char *line);
void 		validate_overlap(int id, int *check_overlap);

// render.c
void		render(t_scene *scene, t_screen *screen);
void		camera_init(t_camera *camera);
t_color3	get_pixel_color(t_scene *scene, int x, int y);
void		draw_pixel(t_screen *screen, t_color3 color, int x, int y);
int			write_color(t_color3 color);

// hit.c
void	init_hit(bool (*fp[4])(t_generic_lst *obj, t_ray *ray, double t_max, t_hit_record *rec));
bool	hit_obj(t_generic_lst *obj, t_ray *ray, double t_max, t_hit_record *rec);
bool	hit_sphere(t_generic_lst *obj, t_ray *ray, double t_max, t_hit_record *rec);
bool	hit_plane(t_generic_lst *obj, t_ray *ray, double t_max, t_hit_record *rec);
bool	hit_cylinder(t_generic_lst *obj, t_ray *ray, double t_max, t_hit_record *rec);
bool	hit_cone(t_generic_lst *obj, t_ray *ray, double t_max, t_hit_record *rec);

// texture.c
t_color3	checker_mapping(t_texture t, t_color3 color, int width, int height);
t_texture	get_spherical_map(t_point3 point);
t_texture	get_planar_map(t_point3 point);
t_texture	get_cylindrical_map(t_point3 point, double height);
t_point3	calibrate_cylinder(t_cylinder *cylinder, t_point3 point);
t_vec3		bump_mapping(t_texture t, int width, int height);

// ray.c
t_point3	ray_at(t_ray *ray, double t);
t_color3	ray_color(t_scene *scene, t_ray *ray);
t_ray		get_ray(t_camera cam, double u, double v);

// phong_lighting.c
t_color3	phong_lighting(t_scene *scene, t_hit_record rec, t_ray ray);
t_color3	point_light(t_generic_lst *obj, t_light light, t_hit_record rec, t_ray ray);
bool		in_shadow(t_generic_lst *obj, t_point3 origin, t_vec3 direction);

// key_hook.c
int		key_hook(int keycode, t_scene *scene);
void	camera_move(int keycode, t_camera *camera);
void	camera_rotation(int keycode, t_camera *camera);
void	mode(int keycode, t_scene *scene);
t_vec3	rodrigues_formula(t_vec3 vec, t_vec3 axis, double angle);

#endif
