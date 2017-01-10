/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 15:16:19 by gdelabro          #+#    #+#             */
/*   Updated: 2017/01/07 14:24:33 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void	trace_disk(int x, int y, int taille, t_wolf *t)
{
	int i;
	int i2;
	int tx;
	int ty;

	i = x - taille;
	i2 = y - taille;
	t->color = 0xFFFFFF;
	while (++i < x + taille && (i2 = y - taille))
		while (++i2 < y + taille)
		{
			tx = i > x ? i - x : x - i;
			ty = i2 > y ? i2 - y : y - i2;
			if (tx * tx + ty * ty <= taille * taille
					&& i < t->imgx && i2 < t->imgy)
				ft_memcpy(t->img_ptr + 4 * t->imgx * i2 + 4 * i, &t->color, 4);
		}
}

void	trace_cercle(int x, int y, int taille, t_wolf *t)
{
	int i;
	int i2;
	int tx;
	int ty;

	i = x - taille;
	i2 = y - taille;
	t->color = 0xFFFFFF;
	while (++i < x + taille && (i2 = y - taille))
		while (++i2 < y + taille)
		{
			tx = i > x ? i - x : x - i;
			ty = i2 > y ? i2 - y : y - i2;
			if (tx * tx + ty * ty <= taille * taille
					&& i < t->imgx && i2 < t->imgy
					&& tx * tx + ty * ty >= taille * taille - 2 * taille)
				ft_memcpy(t->img_ptr + 4 * t->imgx * i2 + 4 * i, &t->color, 4);
		}
}
