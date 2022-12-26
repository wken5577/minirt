/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 11:25:40 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/12/26 13:43:55 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

# include<mlx.h>
# include<stdlib.h>

// mlx 구조체
typedef struct s_vars {
	void		*mlx;
	void		*win;
}				t_vars;

// image data 구조체
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data;

typedef struct s_color
{
	double	x;
	double	y;
	double	z;
}	t_color;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		write_color(int t, t_color *pixel_color);
t_color	color(double x, double y, double z);
int		key_hook(int keycode, t_vars *vars);
int		exit_hook(void);

#endif