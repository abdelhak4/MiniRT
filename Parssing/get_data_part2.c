 #include "../Include/miniRT.h"

int    get_Plane(t_minirt *mini, t_data *data)
{
    int     empty;
    t_Plane *_plane;

    empty = 1;
    if (!mini->Plane)
        empty = 0;
    _plane = ft_calloc(1, sizeof(t_Plane));
    set_cordinates(data->pars[1], &_plane->plane_point, mini);
    set_orientation(data->pars[2], &_plane->normal, mini);
    set_color(data->pars[3], _plane->color, mini);
    if (empty)
        rt_last_Plane(mini->Plane)->next = _plane;
    else
        mini->Plane = _plane;
    return 1;
}

int    get_Sphere(t_minirt *mini, t_data *data)//**Spher
{
    int      empty;
    t_Sphere *_sphere;

    empty = 1;
    if (!mini->Sphere)
        empty = 0;
    _sphere = ft_calloc(1, sizeof(t_Sphere));
    set_cordinates(data->pars[1], &_sphere->center, mini);
    _sphere->radius = ft_atod(data->pars[2], &mini->check) / 2;
    if (mini->check)
    {
        free_mini(mini);
        exit(EXIT_FAILURE);
    }
    set_color(data->pars[3], _sphere->color, mini);
    if (empty)
        rt_last_Sphere(mini->Sphere)->next = _sphere;
    else
        mini->Sphere = _sphere;
    return 1;
}

int    get_Cylinder(t_minirt *mini, t_data *data)
{
    int         empty;
    t_Cylinder *_cylinder;

    empty = 1;
    if (!mini->Cylinder)
        empty = 0;
    _cylinder = ft_calloc(1, sizeof(t_Cylinder));
    set_cordinates(data->pars[1], &_cylinder->cordinates, mini);
    set_orientation(data->pars[2], &_cylinder->orientation, mini);
	/*
	 *  todo : ! turn atod from double to float !
	 */
    _cylinder->redius = ft_atod(data->pars[3], &mini->check) / 2;
    _cylinder->height = ft_atod(data->pars[4], &mini->check);
    if (mini->check)
    {
        free_mini(mini);
        exit(EXIT_FAILURE);
    }
    set_color(data->pars[5], _cylinder->color, mini);
    if (empty)
        rt_last_Cylinder(mini->Cylinder)->next = _cylinder;
    else
        mini->Cylinder = _cylinder;
    return 1;
}