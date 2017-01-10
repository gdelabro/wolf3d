/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_to_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 17:44:58 by gdelabro          #+#    #+#             */
/*   Updated: 2017/01/10 16:14:02 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

static int		ft_taille(t_wolf *t, char c)
{
	int i;

	i = -1;
	if (c == 'y')
		while (t->tab[++i])
			;
	if (c == 'x')
		while (t->tab[0][++i])
			;
	return (i);
}

static void		ft_remplir(t_wolf *t)
{
	int i;

	i = -1;
	t->map[t->tmp] = (int**)malloc(sizeof(*(t->map)) * t->xmax);
	while (++i < t->xmax)
	{
		t->map[t->tmp][i] = (int*)malloc(sizeof(int) * 1);
		t->map[t->tmp][i][0] = ft_atoi(t->tab[t->tmp][i]);
	}
}

void			tab_to_map(t_wolf *t)
{
	t->tmp = -1;
	t->ymax = ft_taille(t, 'y');
	t->map = (int***)malloc(sizeof(**t->map) * t->ymax);
	t->xmax = ft_taille(t, 'x');
	while (++t->tmp < t->ymax)
		ft_remplir(t);
}
