/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhakki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 23:38:58 by melhakki          #+#    #+#             */
/*   Updated: 2019/11/16 23:41:19 by melhakki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_hook(int button, int x, int y, t_all *this)
{
	double	interpolation;

	if (button == 5)
	{
		this->iter += 50;
		interpolation = 0.9 / 1.01;
		zoom(this, (double)x, (double)y, interpolation);
		this->gliss *= 0.9;
	}
	else if (button == 4)
	{
		this->iter -= 50;
		interpolation = 1.01 / 0.9;
		zoom(this, (double)x, (double)y, interpolation);
		this->gliss *= 1.1;
	}
	if (this->type == 'm')
		mandelbrot(this);
	else if (this->type == 'j')
		julia(this);
	else if (this->type == 'b')
		burning_ship(this);
	mlx_put_image_to_window(this->init, this->win, this->img, 0, 0);
	return (1);
}

int		motion_hook(int x, int y, t_all *this)
{
	if (this->f)
	{
		this->c_x = (x / ((double)WIDTH /
					fabs(this->x_i - this->x_f)) + this->x_i);
		this->c_y = (y / ((double)HIGHT /
					fabs(this->y_i - this->y_f)) + this->y_i);
	}
	julia(this);
	mlx_put_image_to_window(this->init, this->win, this->img, 0, 0);
	this->tmp++;
	return (1);
}

void	press_hook2(t_all *this, int button)
{
	double	interpolation;

	if (button == 116)
	{
		this->iter += 50;
		interpolation = 0.9 / 1.01;
		zoom(this, (double)WIDTH / 2, (double)HIGHT / 2, interpolation);
		this->gliss *= 0.9;
	}
	else if (button == 121)
	{
		this->iter -= 50;
		interpolation = 1.01 / 0.9;
		zoom(this, (double)WIDTH / 2, (double)HIGHT / 2, interpolation);
		this->gliss *= 1.1;
	}
}

void	press_hook3(t_all *this, int button)
{
	if (button == 125)
	{
		this->y_i += this->gliss;
		this->y_f += this->gliss;
	}
	else if (button == 126)
	{
		this->y_i -= this->gliss;
		this->y_f -= this->gliss;
	}
	else if (button == 123)
	{
		this->x_i -= this->gliss;
		this->x_f -= this->gliss;
	}
	else if (button == 124)
	{
		this->x_i += this->gliss;
		this->x_f += this->gliss;
	}
}

int		press_hook(int button, t_all *this)
{
	if (button == 53)
		exit(0);
	press_hook2(this, button);
	press_hook3(this, button);
	if (button == 3)
	{
		if (this->f == 1)
			this->f = 0;
		else
			this->f = 1;
	}
	else if (button == 49)
		this->color = rand();
	if (this->type == 'm')
		mandelbrot(this);
	else if (this->type == 'j')
		julia(this);
	else if (this->type == 'b')
		burning_ship(this);
	mlx_put_image_to_window(this->init, this->win, this->img, 0, 0);
	return (1);
}
