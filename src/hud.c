/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 17:14:55 by gdelabro          #+#    #+#             */
/*   Updated: 2017/01/05 18:13:10 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void	show_hud(t_wolf *t)
{
	if (t->hud == 1)
	{
		mlx_string_put(t->mlx, t->win, 10, 10, 0xEEEEEE,
				"Press W A S D to move.");
		mlx_string_put(t->mlx, t->win, 10, 30, 0xEEEEEE,
			"Press SHIFT to sprint.");
		mlx_string_put(t->mlx, t->win, 10, 50, 0xEEEEEE,
				"Press DEL to reset the level.");
		mlx_string_put(t->mlx, t->win, 10, 70, 0xEEEEEE,
				"Press H to show or HUD.");
		mlx_string_put(t->mlx, t->win, 10, 90, 0xEEEEEE,
				"Press ESC to quit.");
	}
}
