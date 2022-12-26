/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 11:23:14 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/12/26 13:14:42 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	write_color(int t, t_color *pixel_color)
{
	return (t << 24 | (int)(255 * pixel_color->x) << 16 | \
		(int)(255 * pixel_color->y) << 8 | (int)(255 * pixel_color->z));
}

t_color	color(double x, double y, double z)
{
	t_color	out;

	out.x = x;
	out.y = y;
	out.z = z;
	return (out);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	exit_hook(void)
{
	exit(0);
}
