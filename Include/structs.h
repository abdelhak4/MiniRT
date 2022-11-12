#pragma once
#include "miniRT.h"
/********* struct for test ********/


/*
 *  we could represent the color by percentage
 *  between 0.0 to 1.0
 * */
/*
typedef struct s_color {
	float red, green, blue;
} colour;


typedef struct s_material{
	colour diffuse;
	float	reflection;
}	t_material;

typedef struct	s_light {
	t_point	pos;
	colour 	intensity;
}	t_light;


typedef struct	s_sphere {
	t_point	pos;
	float	radius;
	int		material;
}	t_sphere;
*/

/********************/
typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*adr;
	int		width;
	int		height;
    int		bits_per_pixel;
    int		line_length;
	int		endian;
}			t_mlx;

typedef struct _data {

    char    *info;//change
    char    **pars;
    int     check_empty;
    struct _data *next;

}   t_data;

typedef struct	point {

	float	x;
	float	y;
	float	z;
}	t_point;

    // t_point left_corner;
    // t_point horizontal;
    // t_point vertical; 
typedef struct	s_ray {
    
    t_point origin;
    t_point direction;
    float   t;
}	t_ray;

typedef struct matrix
{
	float	M[4][4];
}				t_matrix;

typedef struct _Ambient_light
{
    float   ratio;//ambient lighting ratio in range [0.0,1.0]:
    size_t  color[3];//R,G,B colors in range [0-255]: 255, 255, 255
    size_t  repetition;
} t_Ambient;

typedef struct _Camera
{
    size_t    fov;// ->
    size_t    repetition;
    t_ray	  ray;
    t_matrix  matrix;
} t_Camera;

typedef struct _Light
{
    t_point   cordinates;//x,y,z coordinates of the view
    float    brightenss;//the light brightness ratio in range [0.0,1.0]
    size_t   color[3];//R,G,B colors in range [0-255]: 255, 255, 255
    size_t   repetition;
} t_Light;

typedef struct _Plane
{
    t_point         plane_point;//x,y,z coordinates of the view
    t_point         normal;//3d normalized orientation vector. In range [-1,1] 
    t_ray	        ray;
    size_t          color[3];//R,G,B colors in range [0-255]: 255, 255, 255
    size_t          repetition;
    struct _Plane   *next;
} t_Plane;

typedef struct _Sphere
{
    t_point         center;//x,y,z coordinates of the view
    float			radius;
    size_t			color[3];//R,G,B colors in range [0-255]: 255, 255, 255
    size_t			repetition;
    struct _Sphere   *next;
} t_Sphere;

typedef struct _Cylinder
{
    t_point             cordinates;//x,y,z coordinates of the view
    t_point             orientation;//3d normalized orientation vector. In range [-1,1] 
    size_t              color[3];//R,G,B colors in range [0-255]: 255, 255, 255
    float               redius;
    float               height;
    size_t              repetition;
    struct _Cylinder    *next;
} t_Cylinder;

typedef struct _minirt {

    int         fd;
    int         check;
    char        *file;
    t_Ambient   *Ambient;
    t_Camera    *Camera;
    t_Light     *Light;
    t_Sphere    *Sphere;
    t_Plane     *Plane;
    t_Cylinder  *Cylinder;
    t_data      *Data;
    t_mlx       *Mlx;
}   t_minirt;
