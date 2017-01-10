/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 12:23:59 by gdelabro          #+#    #+#             */
/*   Updated: 2017/01/10 15:15:49 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include "libft/libft.h"
# define PI 3.14159265358979323846

typedef struct	s_wolf
{
	int			tmp;
	int			pcx;
	int			pcy;
	int			dirx;
	int			diry;
	int			y;
	int			x;
	double		ang;
	double		ang2;
	int			fov;
	int			imgx;
	int			imgy;
	int			xmax;
	int			ymax;
	int			dist;
	int			m_up;
	int			m_down;
	int			m_right;
	int			m_left;
	double		ms;
	char		*file;
	char		***tab;
	int			***map;
	int			hud;
	void		*mlx;
	void		*win;
	void		*img;
	void		*img_ptr;
	int			endian;
	int			taille;
	int			bpp;
	int			sl;
	int			color;
}				t_wolf;

void			ft_quit(int i);
int				ft_close(void);
char			***ft_file_to_tab(char *file);
void			ft_test_file(char ***tab);
void			tab_to_map(t_wolf *t);
void			show_hud(t_wolf *t);
int				loop_hook(t_wolf *t);
int				key_press(int keycode, t_wolf *t);
int				key_release(int keycode, t_wolf *t);
void			t_init(t_wolf *t, char *file);
int				raycasting(t_wolf *t);
void			trace_cercle(int x, int y, int taille, t_wolf *t);
void			trace_disk(int x, int y, int taille, t_wolf *t);
void			ft_move(t_wolf *t);

#endif
