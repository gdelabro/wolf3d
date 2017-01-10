/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 16:25:49 by gdelabro          #+#    #+#             */
/*   Updated: 2017/01/07 15:45:23 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

int		key_press(int keycode, t_wolf *t)
{
	ft_putstr("key: ");
	ft_putnbr(keycode);
	ft_putendl("");
	t->tmp = t->hud;
	keycode == 4 && t->hud == 0 ? t->hud = 1 : 0;
	keycode == 4 && t->tmp == 1 ? t->hud = 0 : 0;
	keycode == 13 || keycode == 126 ? t->m_up = 1 : 0;
	keycode == 1 || keycode == 125 ? t->m_down = 1 : 0;
	keycode == 2 || keycode == 124 ? t->m_right = 1 : 0;
	keycode == 0 || keycode == 123 ? t->m_left = 1 : 0;
	keycode == 257 || keycode == 258 ? t->ms = 0.1 : 0;
	keycode == 53 ? exit(1) : 0;
	keycode == 117 ? t_init(t, t->file) : 0;
	keycode == 78 ? t->fov -= 1 : 0;
	keycode == 69 ? t->fov += 1 : 0;
	return (0);
}

int		key_release(int keycode, t_wolf *t)
{
	keycode == 13 || keycode == 126 ? t->m_up = 0 : 0;
	keycode == 1 || keycode == 125 ? t->m_down = 0 : 0;
	keycode == 2 || keycode == 124 ? t->m_right = 0 : 0;
	keycode == 0 || keycode == 123 ? t->m_left = 0 : 0;
	keycode == 257 || keycode == 258 ? t->ms = 0.5 : 0;
	return (0);
}
