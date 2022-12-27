/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkyu <hyunkyu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:50:43 by hyunkyu           #+#    #+#             */
/*   Updated: 2022/12/27 14:16:50 by hyunkyu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

int get_t(int trgb)
{
  return (trgb & (0xFF << 24));
}

int get_r(int trgb)
{
  return (trgb & (0xFF << 16));
}

int get_g(int trgb)
{
  return (trgb & (0xFF << 8));
}

int get_b(int trgb)
{
  return (trgb & 0xFF);
}
