/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 14:42:51 by gdelabro          #+#    #+#             */
/*   Updated: 2017/01/07 15:06:15 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void	t_init(t_wolf *t, char *file)
{
	t->pcx = 700;
	t->pcy = 700;
	t->fov = 60;
	t->imgx = 800;
	t->imgy = 600;
	t->hud = 1;
	t->ang = 0;
	t->file = file;
	t->tab = ft_file_to_tab(file);
	tab_to_map(t);
}

int		main(int argc, char **argv)
{
	t_wolf t;

	if (argc != 2)
		ft_quit(0);
	t_init(&t, argv[1]);
	t.mlx = mlx_init();
	t.win = mlx_new_window(t.mlx, t.imgx, t.imgy, "wolf3d");
	t.img = mlx_new_image(t.mlx, t.imgx, t.imgy);
	t.img_ptr = mlx_get_data_addr(t.img, &t.bpp, &t.sl, &t.endian);
	mlx_hook(t.win, 17, 0L, ft_close, &t);
	mlx_hook(t.win, 2, (1L << 0), key_press, &t);
	mlx_hook(t.win, 3, (1L << 1), key_release, &t);
	mlx_loop_hook(t.mlx, loop_hook, &t);
	mlx_loop(t.mlx);
	return (1);
}
