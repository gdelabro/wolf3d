/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 18:48:29 by gdelabro          #+#    #+#             */
/*   Updated: 2017/01/10 17:09:28 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"
#include <stdio.h>

static void	ft_calcul_taille_ray(t_wolf *t)
{
	t->dist = 0;
	t->ang2 = (t->tmp - (t->imgy / 2)) * (60 / t->imgy);
	t->dirx = cos(PI * (t->ang + t->ang2) / 180) * 100;
	t->diry = sin(PI * (t->ang + t->ang2) / 180) * 100;
	while (++t->dist)
	{
		t->y = ((t->diry * t->dist) + t->pcy) / 500 % t->ymax;
		t->x = ((t->dirx * t->dist) + t->pcx) / 500 % t->xmax;
		if (t->map[t->y][t->x][0])
			break ;
	}
	t->taille = t->dist ? 277 * 64 / t->dist : 0;
}

static void	ft_ray(t_wolf *t, int i)
{
	t->tmp = -1;
	while (++t->tmp < t->imgx)
	{
		ft_calcul_taille_ray(t);
		if (t->tmp < t->imgy / 2 - t->taille / 2)
			t->color = 0x84DCF2;
		else if (t->tmp < t->imgy / 2 + t->taille / 2)
			t->color = 0xFFA703;
		else
			t->color = 0x323232;
		ft_memcpy(t->img_ptr + 4 * t->imgx * t->tmp + 4 * i, &t->color, 4);
	}
}

int			raycasting(t_wolf *t)
{
	int i;

	i = -1;
	while (++i < t->imgx)
		ft_ray(t, i);
	return (1);
}
