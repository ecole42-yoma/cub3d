/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mouse_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 01:35:17 by yongmkim          #+#    #+#             */
/*   Updated: 2022/07/28 02:48:48 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "key_event.h"
#include "mlx.h"

int	check_mouse_move(t_info *info)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(info->mlx.win, &x, &y);
	if (x < info->bonus.mouse_x)
	{
		key_rotate_view(KC_LEFT, info, MOUSE_SPEED);
	}
	else if (info->bonus.mouse_x < x)
	{
		key_rotate_view(KC_RIGHT, info, MOUSE_SPEED);
	}
	info->bonus.mouse_x = x;
	if (info->bonus.mouse_x < 0 || WIDTH < info->bonus.mouse_x)
	{
		info->bonus.mouse_x = 800;
	}
	return (1);
}
