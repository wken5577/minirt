/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:54:44 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/12/26 19:41:03 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <unistd.h>
# include <fcntl.h>
# include "../mini_rt.h"
# include "../get_next_line/get_next_line_bonus.h"
# include "../libft/libft.h"

void	init_am_light(char **strs, t_info_data *data, int *cnt);
void	init_camera(char **strs, t_info_data *data, int *cnt);
void	init_light(char **strs, t_info_data *data, int *cnt);
void	init_sphere(char **strs, t_info_data *data, int *cnt);
void	init_plain(char **strs, t_info_data *data, int *cnt);

#endif