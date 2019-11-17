/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhakki <melhakki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 15:58:45 by melhakki          #+#    #+#             */
/*   Updated: 2019/11/16 23:33:10 by melhakki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_prog(t_all *this, char type)
{
	int		b_p;
	int		s_l;
	int		endian;

	this->init = mlx_init();
	this->win = mlx_new_window(this->init, HIGHT, WIDTH, "fract'ol");
	this->img = mlx_new_image(this->init, HIGHT, WIDTH);
	this->img_str = (unsigned char *)mlx_get_data_addr(this->img,
			&b_p, &s_l, &endian);
	this->type = type;
	this->x_i = -2;
	this->x_f = 2;
	this->y_i = -2;
	this->y_f = 2;
	this->iter_max = 50;
	this->zoom = 0;
	this->color = rand();
	this->gliss = 0.2;
	this->c_x = 0.285;
	this->c_y = 0.01;
	this->tmp = 0;
	this->f = 1;
}

double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

void	zoom(t_all *this, double x, double y, double interpolation)
{
	double	xx;
	double	yy;

	xx = x / ((double)WIDTH / (this->x_f - this->x_i)) + this->x_i;
	yy = y / ((double)HIGHT / (this->y_f - this->y_i)) + this->y_i;
	this->x_i = interpolate(xx, this->x_i, interpolation);
	this->y_i = interpolate(yy, this->y_i, interpolation);
	this->x_f = interpolate(xx, this->x_f, interpolation);
	this->y_f = interpolate(yy, this->y_f, interpolation);
}

int		types(t_all *this, char *av)
{
	if (ft_strcmp(av, "mandelbrot") == 0)
	{
		init_prog(this, 'm');
		mandelbrot(this);
	}
	else if (ft_strcmp(av, "julia") == 0)
	{
		init_prog(this, 'j');
		julia(this);
	}
	else if (ft_strcmp(av, "burningship") == 0)
	{
		init_prog(this, 'b');
		burning_ship(this);
	}
	else
	{
		ft_putstr("Usage : ./fractol [mandelbrot || julia || burningship]\n");
		return (0);
	}
	return (1);
}

int		main(int ac, char *av[])
{
	t_all	this;

	this.f = 1;
	if (ac == 2)
	{
		if (types(&this, av[1]) == 0)
			return (0);
		mlx_put_image_to_window(this.init, this.win, this.img, 0, 0);
		mlx_hook(this.win, 4, 0, mouse_hook, &this);
		mlx_hook(this.win, 2, 0, press_hook, &this);
		if (this.type == 'j')
			mlx_hook(this.win, 6, 0, motion_hook, &this);
		mlx_loop(this.init);
	}
	else
		ft_putstr("Usage : ./fractol [mandelbrot || julia || burningship]\n");
	return (0);
}
