/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_down.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:31:58 by ccamie            #+#    #+#             */
/*   Updated: 2022/07/18 15:45:53 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "key.h"
#include "event.h"
#include "ray.h"

static void	movement(t_key key, t_vec3 *direction, t_bool *move)
{
	t_vec3	vector;

	vector = *direction;
	if (key == KEY_W)
		vector = vec3_add(vector, vec3_new(1.0, 0.0, 0.0));
	else if (key == KEY_A)
		vector = vec3_add(vector, vec3_new(0.0, -1.0, 0.0));
	else if (key == KEY_S)
		vector = vec3_add(vector, vec3_new(-1.0, 0.0, 0.0));
	else if (key == KEY_D)
		vector = vec3_add(vector, vec3_new(0.0, 1.0, 0.0));
	else if (key == KEY_SPASE)
		vector = vec3_add(vector, vec3_new(0.0, 0.0, -1.0));
	else if (key == KEY_SHIFT)
		vector = vec3_add(vector, vec3_new(0.0, 0.0, 1.0));
	else
		return ;
	*move = TRUE;
	*direction = vector;
}

static void	check_fov(t_key key, float *change, t_bool *fov)
{
	if (key == KEY_PLUS)
		*change += -0.5;
	else if (key == KEY_MINUS)
		*change += +0.5;
	else
		return ;
	*fov = TRUE;
}

static void	check_block(t_key key, int *block)
{
	if (key == KEY_ONE)
		*block = 1;
	else if (key == KEY_TWO)
		*block = 2;
	else if (key == KEY_THREE)
		*block = 4;
	else if (key == KEY_FOUR)
		*block = 8;
	else if (key == KEY_FIVE)
		*block = 16;
	else
		return ;
}

static void	check_smooth(t_key key, int *smooth)
{
	if (key == KEY_C)
		*smooth = !*smooth;
	else
		return ;
}

static float	axes_x(t_ray ray, t_vec3 origin)
{
	t_vec3	t;

	t.y = (origin.y - ray.origin.y) / ray.direction.y;
	t.z = (origin.z - ray.origin.z) / ray.direction.z;
	t.x = ray.origin.x + ray.direction.x * t.z;
	return (t.x);
}

float	axes_y(t_ray ray, t_vec3 origin)
{
	t_vec3	t;

	t.x = (origin.x - ray.origin.x) / ray.direction.x;
	t.z = (origin.z - ray.origin.z) / ray.direction.z;
	t.y = ray.origin.y + ray.direction.y * t.z;
	return (t.y);
}

float	axes_z(t_ray ray, t_vec3 origin)
{
	t_vec3	t;

	t.x = (origin.x - ray.origin.x) / ray.direction.x;
	t.y = (origin.y - ray.origin.y) / ray.direction.y;
	t.z = ray.origin.z + ray.direction.z * t.x;
	return (t.z);
}

int	mouse_axes_x(int x, int y, t_scene *scene)
{
	t_sphere	*sphere;
	t_ray		ray;
	t_vec2		pixel;

	sphere = (t_sphere *)scene->object.target;
	pixel = scene->press.mouse.vector;
	ray = ray_new(pixel, scene->camera, scene->option.matrix);
	sphere->location.x = axes_x(ray, sphere->location);;
	scene->press.mouse.vector = vec2_new(x, y);
	scene->press.mouse.action = TRUE;
	return (0);
}

int	mouse_axes_y(int x, int y, t_scene *scene)
{
	t_sphere	*sphere;
	t_ray		ray;
	t_vec2		pixel;

	sphere = (t_sphere *)scene->object.target;
	pixel = scene->press.mouse.vector;
	ray = ray_new(pixel, scene->camera, scene->option.matrix);
	sphere->location.y = axes_y(ray, sphere->location);;
	scene->press.mouse.vector = vec2_new(x, y);
	scene->press.mouse.action = TRUE;
	return (0);
}

int	mouse_axes_z(int x, int y, t_scene *scene)
{
	t_sphere	*sphere;
	t_ray		ray;
	t_vec2		pixel;

	sphere = (t_sphere *)scene->object.target;
	pixel = scene->press.mouse.vector;
	ray = ray_new(pixel, scene->camera, scene->option.matrix);
	sphere->location.z = axes_z(ray, sphere->location);;
	scene->press.mouse.vector = vec2_new(x, y);
	scene->press.mouse.action = TRUE;
	return (0);
}

int	mouse_vector_x(int x, int y, t_scene *scene)
{
	scene->press.mouse.vector = vec2_new(x, y);
	mlx_hook(scene->mlx.win, ON_MOUSEMOVE, 0, mouse_axes_x, scene);
	return (0);
}

int	mouse_vector_y(int x, int y, t_scene *scene)
{
	scene->press.mouse.vector = vec2_new(x, y);
	mlx_hook(scene->mlx.win, ON_MOUSEMOVE, 0, mouse_axes_y, scene);
	return (0);
}

int	mouse_vector_z(int x, int y, t_scene *scene)
{
	scene->press.mouse.vector = vec2_new(x, y);
	mlx_hook(scene->mlx.win, ON_MOUSEMOVE, 0, mouse_axes_z, scene);
	return (0);
}

int	key_down(t_key key, t_scene *scene)
{
	scene->press.key.count += 1;
	scene->press.key.action = TRUE;
	scene->press.key.code = key;
	if (key == KEY_X)
	{
		if (scene->object.type == NIL)
		{
			return (0);
		}
		scene->object.x = TRUE;
		scene->object.y = FALSE;
		scene->object.z = FALSE;
		mlx_hook(scene->mlx.win, ON_MOUSEMOVE, 0, mouse_vector_x, scene);

	}
	if (key == KEY_Y)
	{
		if (scene->object.type == NIL)
		{
			return (0);
		}
		scene->object.x = FALSE;
		scene->object.y = TRUE;
		scene->object.z = FALSE;
		mlx_hook(scene->mlx.win, ON_MOUSEMOVE, 0, mouse_vector_y, scene);
	}
	if (key == KEY_Z)
	{
		if (scene->object.type == NIL)
		{
			return (0);
		}
		scene->object.x = FALSE;
		scene->object.y = FALSE;
		scene->object.z = TRUE;
		mlx_hook(scene->mlx.win, ON_MOUSEMOVE, 0, mouse_vector_z, scene);
	}
	movement(key, &(scene->press.key.direction), &(scene->press.key.move));
	check_fov(key, &(scene->press.key.change), &(scene->press.key.fov));
	check_block(key, &(scene->option.block));
	check_smooth(key, &(scene->option.smooth));
	if (key == KEY_ESC)
		terminate(scene);
	return (0);
}
