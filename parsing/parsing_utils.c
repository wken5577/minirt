/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 19:26:54 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/12/26 19:47:19 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	init_am_light(char **strs, t_info_data *data, int *cnt)
{
	char	**color_data;

	if (ft_strs_size(strs) != 3)
		ft_print_exit();
	color_data = ft_split(strs[2], ',');
	if (ft_strs_size(color_data) != 3)
		ft_print_exit();
}

void	init_camera(char **strs, t_info_data *data, int *cnt)
{
}

void	init_light(char **strs, t_info_data *data, int *cnt)
{
}

void	init_sphere(char **strs, t_info_data *data, int *cnt)
{
}

void	init_plain(char **strs, t_info_data *data, int *cnt)
{
}
