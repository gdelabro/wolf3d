/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 14:53:38 by gdelabro          #+#    #+#             */
/*   Updated: 2017/01/10 15:19:02 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void	ft_move(t_wolf *t)
{
	if (t->m_right == 1)
		t->ang += 1;
	if (t->m_left == 1)
		t->ang -= 1;
	if (t->m_up == 1)
		t->pcx += t->dirx * t->ms;
	if (t->m_down == 1)
		t->pcy += t->diry * t->ms;
}

int		loop_hook(t_wolf *t)
{
	t->dirx = cos(PI * t->ang / 180) * 100;
	t->diry = sin(PI * t->ang / 180) * 100;
	raycasting(t);
	t->hud == 1 ? trace_cercle(t->imgx / 2, t->imgy / 2, 7, t) : 0;
	t->hud == 1 ? trace_disk(t->imgx / 2, t->imgy / 2, 2, t) : 0;
	mlx_put_image_to_window(t->mlx, t->win, t->img, 0, 0);
	show_hud(t);
	return (1);
}

int		ft_close(void)
{
	exit(1);
	return (0);
}

void	ft_quit(int i)
{
	if (i == 0)
		ft_putendl("usage: ./wolf3d maps_name");
	exit(1);
}
