/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyu <hyunkyu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 19:26:54 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/12/27 14:57:25 by hyunkyu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	init_am_light(char **strs, t_info_data *data)
{
	char			**color_data;
	t_am_lightning	am_light;

	if (ft_strs_size(strs) != 3)
		ft_print_exit();
	am_light.ratio_in_range = ft_atof(strs[1]);
	color_data = ft_split(strs[2], ',');
	if (ft_strs_size(color_data) != 3)
		ft_print_exit();
	am_light.color_range = create_trgb(0, ft_atoi(color_data[0]), \
			ft_atoi(color_data[1]), ft_atoi(color_data[2]));
	ft_release_strs(color_data);
	data->am_light = am_light;
}

void	init_camera(char **strs, t_info_data *data)
{
	char		**tmp;
	t_camera	camera;

	if (ft_strs_size(strs) != 4)
		ft_print_exit();
	tmp = ft_split(strs[1], ',');
	if (!tmp || ft_strs_size(tmp) != 3)
		ft_print_exit();
	camera.coordinates = vec(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2]));
	ft_release_strs(tmp);
	tmp = ft_split(strs[2], ',');
	if (!tmp || ft_strs_size(tmp) != 3)
		ft_print_exit();
	camera.nor_vector = vec(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2]));
	ft_release_strs(tmp);
	camera.fov = ft_atof(strs[3]);
	data->camera = camera;
}

void	init_light(char **strs, t_info_data *data)
{
	char	**tmp;
	t_light	light;

	if (ft_strs_size(strs) != 4)
		ft_print_exit();
	tmp = ft_split(strs[1], ',');
	if (!tmp || ft_strs_size(tmp) != 3)
		ft_print_exit();
	light.coordinates = vec(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2]));
	ft_release_strs(tmp);
	light.ratio_in_range = ft_atof(strs[2]);
	tmp = ft_split(strs[3], ',');
	if (!tmp || ft_strs_size(tmp) != 3)
		ft_print_exit();
	light.color_range = create_trgb(0, ft_atoi(tmp[0]), ft_atoi(tmp[1]), \
			ft_atoi(tmp[2]));
	ft_release_strs(tmp);
	data->light = light;
}
