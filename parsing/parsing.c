/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:54:36 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/12/26 19:45:11 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

#define _DATA_LEN 6

static const char	*g_data[6] = {
	"A", "C", "L", "pl", "sp", "cy"
};

static const void	(*g_functions[6])(char **, t_info_data *, int *) = {
	init_am_light, init_camera, init_light, \
		init_sphere, init_plain, init_cylinder
};

void	init_cylinder(char **strs, t_info_data *data, int *cnt)
{
}

void	fill_data(char *line, t_info_data *data, int *cnt)
{
	char	**strs;
	int		i;

	strs = ft_split(line, ' ');
	if (!strs)
		exit(0);
	if (ft_strs_size(strs) == 0)
		ft_print_exit();
	i = 0;
	while (i < _DATA_LEN)
	{
		if (ft_strcmp(strs[0], g_data[i]) == 0)
			break ;
		i++;
	}
	if (i == _DATA_LEN)
		ft_print_exit();
	g_functions[i](strs, data, cnt);
}

void	get_info_data(char *filename, t_info_data *data)
{
	int			fd;
	char		*line;
	int			cnt;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit(0);
	cnt = 0;
	line = get_next_line(fd);
	while (line)
	{
		fill_data(line, data, &cnt);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
