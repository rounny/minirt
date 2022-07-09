/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:21:46 by ccamie            #+#    #+#             */
/*   Updated: 2022/07/08 16:17:30 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	write_pixel(t_view view, t_vec2 pixel, t_vec3 color)
{
	unsigned char	*buffer;
	int				_pixel;

	if (pixel.x < 0.0 || pixel.x > WIDTH || pixel.y < 0.0 || pixel.y > HEIGHT)
	{
		printf("\a\x1b[41m\x1b[1m 💥 BOOM 💥 \x1b[0m\n");
		exit(1);
	}
	buffer = (unsigned char *)view.buffer;
	_pixel = (pixel.y * view.line) + (pixel.x * 4);
	buffer[_pixel + 0] = color.z * 255;
	buffer[_pixel + 1] = color.y * 255;
	buffer[_pixel + 2] = color.x * 255;
}

void	write_pixels(t_view view, t_vec2 pixel, t_vec3 color, float block)
{
	float	x;
	float	y;
	float	temp;

	temp = pixel.x;
	y = pixel.y + block;
	if (y > HEIGHT)
		y = HEIGHT;
	x = pixel.x + block;
	if (x > WIDTH)
		x = WIDTH;
	while (pixel.y < y)
	{
		pixel.x = temp;
		while (pixel.x < x)
		{
			write_pixel(view, pixel, color);
			pixel.x += 1;
		}
		pixel.y += 1;
	}
}
