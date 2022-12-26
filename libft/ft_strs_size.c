/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 19:24:54 by hyunkyle          #+#    #+#             */
/*   Updated: 2022/12/26 19:25:47 by hyunkyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strs_size(char **strs)
{
	int	i;

	if (!strs)
		return (0);
	i = 0;
	while (strs[i])
		i++;
	return (i);
}