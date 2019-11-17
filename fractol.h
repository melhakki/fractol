/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhakki <melhakki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:51:16 by melhakki          #+#    #+#             */
/*   Updated: 2019/11/17 15:54:17 by melhakki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "mlx.h"
# include <math.h>
# define HIGHT 800
# define WIDTH 800
# define REPERE_X(x) (x / ((double)WIDTH / (this->x_f - this->x_i)) + this->x_i)
# define REPERE_Y(y) (y / ((double)HIGHT / (this->y_f - this->y_i)) + this->y_i)

typedef	struct		s_cord
{
	int				x;
	int				y;
}					t_cord;

typedef	struct		s_all
{
	void			*init;
	void			*img;
	void			*win;
	unsigned char	*img_str;
	int				x;
	int				y;
	double			x_i;
	double			x_f;
	double			y_i;
	double			y_f;
	double			c_x;
	double			c_y;
	double			z_x;
	double			z_y;
	int				iter;
	int				iter_max;
	double			tmp;
	int				zoom;
	int				color;
	double			gliss;
	int				f;
	char			type;
}					t_all;

void				line_draw(t_cord pi, t_cord pf, t_all this);
void				ft_light_pixel(t_all start, int x, int y, int color);
int					mouse_hook(int button, int x, int y, t_all *this);
int					motion_hook(int x, int y, t_all *this);
int					press_hook(int button, t_all *this);
void				mandelbrot(t_all *this);
void				burning_ship(t_all *this);
void				julia(t_all *this);
void				zoom(t_all *this, double x, double y, double interpolation);

#endif
